#pragma once
#include "cb/cb_define.h"
#include "cb/container/cb_range.h"
#include "cb/stream/cb_read_only_span.h"
#include <cstdint>

namespace cb
{
	///
	/// @brief 引用一段连续内存，不持有这段内存。
	///
	/// @warning 要求本类对象的生命周期内，引用的外部内存始终存活。
	///
	/// @note 本类的很多方法都有 const 修饰符。这并不是说不会改变所引用的内存，
	/// 而是不会改变本对象的字段，即不会变成引用别的内存，或者更改引用的内存段大小。
	///
	class Span
	{
	private:
		uint8_t *_buffer = nullptr;
		int64_t _size = 0;

	public:
		/* #region 生命周期 */

		///
		/// @brief 无参构造函数。引用一段空内存。
		///
		/// @note 可以通过 Size 属性判断本对象是否引用到了有效的内存。
		///
		Span() = default;

		///
		/// @brief 引用 buffer 指向的内存。在本对象的生命周期内，buffer 指向的内存必须始终存活。
		///
		/// @param buffer 要引用的内存。
		/// @param size buffer 的大小。
		///
		Span(uint8_t *buffer, int64_t size)
		{
			_buffer = buffer;
			_size = size;

			if (_buffer == nullptr)
			{
				_size = 0;
			}
		}

		///
		/// @brief 引用字符串的内存段。不包括结尾的空字符。
		///
		/// @param str
		///
		Span(char *str)
		{
			int64_t white_char_index = 0;
			while (true)
			{
				if (str[white_char_index] == '\0')
				{
					break;
				}

				white_char_index++;
			}

			_buffer = reinterpret_cast<uint8_t *>(str);
			_size = white_char_index;
		}

		/* #endregion */

		/* #region 索引器 */

		///
		/// @brief 索引一个字节。
		///
		/// @param index
		///
		/// @return
		///
		uint8_t &operator[](int64_t index) const
		{
			__cb_assert(index >= 0 && index < _size, "索引超出范围。");
			return _buffer[index];
		}

		///
		/// @brief 获得指定范围的切片。
		///
		/// @param range
		///
		/// @return
		///
		cb::Span operator[](cb::Range const &range) const
		{
			return Slice(range);
		}

		/* #endregion */

		///
		/// @brief 所引用的内存。
		///
		/// @return
		///
		uint8_t *Buffer() const
		{
			return _buffer;
		}

		///
		/// @brief 所引用的内存大小。
		///
		/// @return
		///
		int64_t Size() const
		{
			return _size;
		}

		///
		/// @brief 翻转本 Span 所引用的内存段。
		///
		void Reverse() const
		{
			std::reverse(_buffer, _buffer + _size);
		}

		/* #region Slice */

		///
		/// @brief 将本 Span 切片，得到一个更小的 Span.
		///
		/// @param start 切片起始位置。
		/// @param size 切片大小。
		///
		/// @return
		///
		cb::Span Slice(int64_t start, int64_t size) const
		{
			__cb_assert(start >= 0, "start 不能小于 0.");
			__cb_assert(size >= 0, "size 不能小于 0.");
			__cb_assert(start + size <= _size, "切片超出范围。");
			return cb::Span{_buffer + start, size};
		}

		///
		/// @brief 获得指定范围的切片。
		///
		/// @param range
		///
		/// @return
		///
		cb::Span Slice(cb::Range const &range) const
		{
			return Slice(range.Begin(), range.Size());
		}

		/* #endregion */

		/* #region CopyFrom */

		///
		/// @brief 将 span 所引用的内存的数据拷贝过来。
		///
		/// @param span
		///
		void CopyFrom(cb::ReadOnlySpan const &span) const
		{
			__cb_assert(span.Size() == _size, "span 的大小和本对象不一致。");

			std::copy(span.Buffer(),
					  span.Buffer() + span.Size(),
					  _buffer);
		}

		///
		/// @brief 将 span 所引用的内存的数据拷贝过来。
		///
		/// @param span
		///
		void CopyFrom(cb::Span const &span) const
		{
			CopyFrom(cb::ReadOnlySpan{span});
		}

		///
		/// @brief 将 list 的数据拷贝过来。
		///
		/// @param list
		///
		void CopyFrom(std::initializer_list<uint8_t> const &list) const
		{
			__cb_assert(static_cast<int64_t>(list.size()) == _size, "list 的大小和本对象不一致。");

			int64_t i = 0;
			for (uint8_t const &value : list)
			{
				_buffer[i] = value;
				i++;
			}
		}

		/* #endregion */

		/* #region 填充 */

		///
		/// @brief 将本 Span 所引用的内存的每一个字节都填充为 0.
		///
		void FillWithZero()
		{
			// std::fill(_buffer, _buffer + _size, 0);
			FillWith(0);
		}

		///
		/// @brief 将所有字节填充为 value.
		///
		/// @param value
		///
		void FillWith(uint8_t value)
		{
			std::fill(_buffer, _buffer + _size, value);
		}

		/* #endregion */

		/* #region IndexOf */

		///
		/// @brief 从本内存段查找匹配项所在的索引。
		///
		/// @param match 匹配项。
		///
		/// @return 找到了返回匹配位置的索引。没找到返回 -1.
		///
		int64_t IndexOf(uint8_t match) const
		{
			return cb::ReadOnlySpan{*this}.IndexOf(match);
		}

		///
		/// @brief 从本内存段查找匹配项所在的索引。
		///
		/// @param start 查找的起始索引。从此处往后开始查找。
		/// @param match 匹配项。
		///
		/// @return 找到了返回匹配位置的索引。没找到返回 -1.
		///
		int64_t IndexOf(int64_t start, uint8_t match) const
		{
			return cb::ReadOnlySpan{*this}.IndexOf(match);
		}

		///
		/// @brief 从本内存段查找匹配项所在的索引。
		///
		/// @param match 匹配项。
		///
		/// @return 找到了返回匹配位置的索引。没找到返回 -1.
		///
		int64_t IndexOf(cb::ReadOnlySpan const &match) const
		{
			return cb::ReadOnlySpan{*this}.IndexOf(match);
		}

		///
		/// @brief 从本内存段查找匹配项所在的索引。
		///
		/// @param start 查找的起始索引。从此处往后开始查找。
		/// @param match 匹配项。
		///
		/// @return 找到了返回匹配位置的索引。没找到返回 -1.
		///
		int64_t IndexOf(int64_t start, cb::ReadOnlySpan const &match) const
		{
			return cb::ReadOnlySpan{*this}.IndexOf(match);
		}

		/* #endregion */

		/* #region LastIndexOf */

		///
		/// @brief 从后往前查找最后一个匹配项所在的索引。
		///
		/// @param match 匹配项。
		///
		/// @return 找到了返回匹配位置的索引。没找到返回 -1.
		///
		int64_t LastIndexOf(uint8_t match) const
		{
			return cb::ReadOnlySpan{*this}.LastIndexOf(match);
		}

		///
		/// @brief 从 start 索引位置开始，从后往前查找匹配项。
		///
		/// @param start 要从后往前查找的起始索引位置。
		/// @param match 匹配项。
		///
		/// @return 找到了返回匹配位置的索引。没找到返回 -1.
		///
		int64_t LastIndexOf(int64_t start, uint8_t match) const
		{
			return cb::ReadOnlySpan{*this}.LastIndexOf(start, match);
		}

		///
		/// @brief 从后往前查找最后一个匹配位置的索引。
		///
		/// @param match 匹配项。
		///
		/// @return
		///
		int64_t LastIndexOf(cb::ReadOnlySpan const &match) const
		{
			return cb::ReadOnlySpan{*this}.LastIndexOf(match);
		}

		///
		/// @brief 从 start 索引位置开始，从后往前查找匹配项。
		///
		/// @param start 要从后往前查找的起始索引位置。
		/// @param match 匹配项。
		///
		/// @return 找到了返回匹配位置的索引。没找到返回 -1.
		///
		int64_t LastIndexOf(int64_t start, cb::ReadOnlySpan const &match) const
		{
			return cb::ReadOnlySpan{*this}.LastIndexOf(start, match);
		}

		/* #endregion */

		/* #region 开始，结束 */

		///
		/// @brief 检查本内存段是否以 match 开头。
		///
		/// @param match
		///
		/// @return
		///
		bool StartWith(uint8_t match) const
		{
			return cb::ReadOnlySpan{*this}.StartWith(match);
		}

		///
		/// @brief 检查本内存段是否以 match 开头。
		///
		/// @param match
		///
		/// @return
		///
		bool StartWith(cb::ReadOnlySpan const &match) const
		{
			return cb::ReadOnlySpan{*this}.StartWith(match);
		}

		///
		/// @brief 检查本内存段是否以 match 结尾。
		///
		/// @param match
		///
		/// @return
		///
		bool EndWith(uint8_t match) const
		{
			return cb::ReadOnlySpan{*this}.EndWith(match);
		}

		///
		/// @brief 检查本内存段是否以 match 结尾。
		///
		/// @param match
		///
		/// @return
		///
		bool EndWith(cb::ReadOnlySpan const &match) const
		{
			return cb::ReadOnlySpan{*this}.EndWith(match);
		}

		/* #endregion */

		/* #region 比较 */

		///
		/// @brief 比较两段内存。
		///
		/// @note 如果两段内存大小相等，且每个字节都相等，则这两段内存相等。
		///
		/// @note 逐个字节比较，直到找到一对不等的字节，这个字节的大小关系就是内存段的大小
		/// 关系。例如本内存段第 1 个字节就和 another 的第 1 个字节不等了，并且本内存段的第
		/// 1 个字节小于 another 的第 1 个字节，则认为本内存段小于 another.
		///
		/// @param another
		///
		/// @return
		///
		int64_t Compare(cb::ReadOnlySpan const &another) const
		{
			return cb::ReadOnlySpan{*this}.Compare(another);
		}

		///
		/// @brief 比较两段内存。
		///
		/// @note 如果两段内存大小相等，且每个字节都相等，则这两段内存相等。
		///
		/// @note 逐个字节比较，直到找到一对不等的字节，这个字节的大小关系就是内存段的大小
		/// 关系。例如本内存段第 1 个字节就和 another 的第 1 个字节不等了，并且本内存段的第
		/// 1 个字节小于 another 的第 1 个字节，则认为本内存段小于 another.
		///
		/// @param another
		///
		/// @return
		///
		int64_t Compare(cb::Span const &another) const
		{
			return cb::ReadOnlySpan{*this}.Compare(another);
		}

		///
		/// @brief 基于 Compare 方法。
		///
		/// @param another
		///
		/// @return
		///
		bool operator==(cb::ReadOnlySpan const &another) const
		{
			return Compare(another) == 0;
		}

		///
		/// @brief 基于 Compare 方法。
		///
		/// @param another
		///
		/// @return
		///
		bool operator==(cb::Span const &another) const
		{
			return Compare(another) == 0;
		}

		///
		/// @brief 基于 Compare 方法。
		///
		/// @param another
		///
		/// @return
		///
		bool operator<(cb::ReadOnlySpan const &another) const
		{
			return Compare(another) < 0;
		}

		///
		/// @brief 基于 Compare 方法。
		///
		/// @param another
		///
		/// @return
		///
		bool operator<(cb::Span const &another) const
		{
			return Compare(another) < 0;
		}

		///
		/// @brief 基于 Compare 方法。
		///
		/// @param another
		///
		/// @return
		///
		bool operator>(cb::ReadOnlySpan const &another) const
		{
			return Compare(another) > 0;
		}

		///
		/// @brief 基于 Compare 方法。
		///
		/// @param another
		///
		/// @return
		///
		bool operator>(cb::Span const &another) const
		{
			return Compare(another) > 0;
		}

		///
		/// @brief 基于 Compare 方法。
		///
		/// @param another
		///
		/// @return
		///
		bool operator<=(cb::ReadOnlySpan const &another) const
		{
			return Compare(another) <= 0;
		}

		///
		/// @brief 基于 Compare 方法。
		///
		/// @param another
		///
		/// @return
		///
		bool operator<=(cb::Span const &another) const
		{
			return Compare(another) <= 0;
		}

		///
		/// @brief 基于 Compare 方法。
		///
		/// @param another
		///
		/// @return
		///
		bool operator>=(cb::ReadOnlySpan const &another) const
		{
			return Compare(another) >= 0;
		}

		///
		/// @brief 基于 Compare 方法。
		///
		/// @param another
		///
		/// @return
		///
		bool operator>=(cb::Span const &another) const
		{
			return Compare(another) >= 0;
		}

		/* #endregion */

		/* #region 迭代 */

		uint8_t *begin()
		{
			return _buffer;
		}

		uint8_t *end()
		{
			return _buffer + _size;
		}

		uint8_t const *begin() const
		{
			return _buffer;
		}

		uint8_t const *end() const
		{
			return _buffer + _size;
		}

		/* #endregion */

		operator cb::ReadOnlySpan() const
		{
			cb::ReadOnlySpan ret{
				_buffer,
				_size,
			};

			return ret;
		}
	};

} // namespace cb
