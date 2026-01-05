#pragma once
#include "cb/define.h"
#include "cb/math/Counter.h"
#include "cb/Placement.h"
#include <algorithm>
#include <cstdint>

namespace cb
{
	///
	/// @brief 循环缓冲区的双端队列。
	///
	template <typename T, int64_t Size>
	class CircleDeque final
	{
	private:
		alignas(T) uint8_t _memory_block[sizeof(T) * Size]{};
		cb::Counter<uint64_t> _begin{0, Size - 1};
		cb::Counter<uint64_t> _end{0, Size - 1};
		bool _is_full = false;

		T *Buffer()
		{
			return reinterpret_cast<T *>(_memory_block);
		}

		T const *Buffer() const
		{
			return reinterpret_cast<T const *>(_memory_block);
		}

	public:
		~CircleDeque()
		{
			Clear();
		}

		///
		/// @brief 队列中当前元素的数量。
		///
		/// @return
		///
		int64_t Count() const
		{
			if (_is_full)
			{
				return Size;
			}

			return _end - _begin;
		}

		bool IsFull() const
		{
			return _is_full;
		}

		///
		/// @brief 队列的容纳能力。即最多容纳多少个元素。
		///
		/// @return
		///
		int64_t Capacity() const
		{
			return Size;
		}

		///
		/// @brief 从队列末端入队。
		///
		/// @param obj
		///
		void PushBack(T const &obj)
		{
			__cb_assert(!_is_full, "队列已满，无法入队。");
			new (&Buffer()[_end.CurrentValue()]) T{obj};
			_end++;
			if (_begin == _end)
			{
				_is_full = true;
			}
		}

		///
		/// @brief 从队列前端入队。
		///
		/// @param obj
		///
		void PushFront(T const &obj)
		{
			__cb_assert(!_is_full, "队列已满，无法入队。");
			_begin--;

			new (&Buffer()[_begin.CurrentValue()]) T{obj};
			if (_begin == _end)
			{
				_is_full = true;
			}
		}

		///
		/// @brief 丢弃末尾的元素。
		///
		void DiscardBack()
		{
			if (Count() == 0)
			{
				return;
			}

			_end--;
			_is_full = false;
			Buffer()[_end.CurrentValue()].~T();
		}

		///
		/// @brief 从队列末端退队。
		///
		/// @return
		///
		T PopBack()
		{
			__cb_assert(Count() > 0, "队列为空，无法退队。");
			_end--;
			_is_full = false;
			T ret{std::move(Buffer()[_end.CurrentValue()])};
			Buffer()[_end.CurrentValue()].~T();
			return ret;
		}

		///
		/// @brief 尝试从队列末端退队。
		///
		void TryPopBack(cb::Placement<T> &placement)
		{
			if (Count() == 0)
			{
				return;
			}

			_end--;
			_is_full = false;
			placement = std::move(Buffer()[_end.CurrentValue()]);
			Buffer()[_end.CurrentValue()].~T();
		}

		///
		/// @brief 丢弃队列前端的元素。
		///
		void DiscardFront()
		{
			if (Count() == 0)
			{
				return;
			}

			int64_t index = _begin.CurrentValue();
			Buffer()[index].~T();
			_begin++;
			_is_full = false;
		}

		///
		/// @brief 从队列前端退队。
		///
		/// @return
		///
		T PopFront()
		{
			__cb_assert(Count() > 0, "队列为空，无法退队。");
			int64_t index = _begin.CurrentValue();
			T ret{std::move(Buffer()[index])};
			Buffer()[index].~T();
			_begin++;
			_is_full = false;
			return ret;
		}

		///
		/// @brief 尝试从队列前端退队。
		///
		void TryPopFront(cb::Placement<T> &placement)
		{
			if (Count() == 0)
			{
				return;
			}

			int64_t index = _begin.CurrentValue();
			placement = std::move(Buffer()[index]);
			Buffer()[index].~T();
			_begin++;
			_is_full = false;
		}

		///
		/// @brief 清空队列。
		///
		///
		void Clear()
		{
			for (int64_t i = 0; i < Count(); i++)
			{
				Get(i).~T();
			}

			_begin.Reset();
			_end.Reset();
			_is_full = false;
		}

		/* #region 索引器 */

		///
		/// @brief 获取队列最前端的元素。
		///
		/// @return
		///
		T &Front()
		{
			return Get(0);
		}

		///
		/// @brief 获取队列最前端的元素。
		///
		/// @return
		///
		T const &Front() const
		{
			return Get(0);
		}

		///
		/// @brief 获取队列最末尾的元素。
		///
		/// @return
		///
		T &Back()
		{
			return Get(Count() - 1);
		}

		///
		/// @brief 获取队列最末尾的元素。
		///
		/// @return
		///
		T const &Back() const
		{
			return Get(Count() - 1);
		}

		///
		/// @brief 获取指定索引的元素。
		///
		/// @param index
		/// @return
		///
		T &Get(int64_t index)
		{
			__cb_assert(index >= 0 && index < Count(), "索引越界。");
			int64_t real_index = _begin + index;
			return Buffer()[real_index];
		}

		///
		/// @brief 获取指定索引的元素。
		///
		/// @param index
		/// @return
		///
		T const &Get(int64_t index) const
		{
			__cb_assert(index >= 0 && index < Count(), "索引越界。");
			int64_t real_index = _begin + index;
			return Buffer()[real_index];
		}

		///
		/// @brief 设置指定索引的元素。
		///
		/// @param index
		/// @param value
		///
		void Set(int64_t index, T const &value)
		{
			__cb_assert(index >= 0 && index < Count(), "索引越界。");
			int64_t real_index = _begin + index;
			Buffer()[real_index] = value;
		}

		///
		/// @brief 获取指定索引的元素。
		///
		/// @param index
		/// @return
		///
		T &operator[](int64_t index)
		{
			return Get(index);
		}

		///
		/// @brief 获取指定索引的元素。
		///
		/// @param index
		/// @return
		///
		T const &operator[](int64_t index) const
		{
			return Get(index);
		}

		/* #endregion */
	};

} // namespace cb
