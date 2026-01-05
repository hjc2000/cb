#pragma once
#include "cb/cb_define.h"
#include <cstddef>
#include <cstdint>

namespace cb
{
	namespace bit
	{
		/* #region 检查参数合法性 */

		template <typename RegisterType>
		constexpr void CheckBitIndex(int bit_index)
		{
			__cb_assert(bit_index >= 0, "位索引不能 < 0.");
			constexpr int bit_count = 8 * sizeof(RegisterType);
			__cb_assert(bit_index < bit_count, "位索引不能 >= bit_count");
		}

		template <typename RegisterType>
		constexpr void CheckBitRange(int begin, int end)
		{
			__cb_assert(begin >= 0, "begin 不能 < 0.");
			constexpr int bit_count = 8 * sizeof(RegisterType);
			__cb_assert(begin < bit_count, "begin 不能 >= bit_count");

			__cb_assert(end >= 0, "end 不能 < 0.");
			__cb_assert(end <= bit_count, "end 不能 > bit_count");
			__cb_assert(begin <= end, "begin 不能 > end.");
		}

		/* #endregion */

		/* #region 掩码 */

		///
		/// @brief 获取一个只有 bit_index 指定的位为 1, 其他位都为 0 的掩码。
		///
		/// @param bit_index
		/// @return
		///
		constexpr uint64_t Bit(int bit_index)
		{
			CheckBitIndex<uint64_t>(bit_index);
			return static_cast<uint64_t>(0b1) << bit_index;
		}

		///
		/// @brief 最低有效位。
		///
		///
		template <typename RegisterType>
		constexpr RegisterType LSB()
		{
			return static_cast<RegisterType>(1);
		}

		///
		/// @brief 最高有效位。
		///
		///
		template <typename RegisterType>
		constexpr RegisterType MSB()
		{
			uint8_t bit_count = sizeof(RegisterType) * 8;
			return static_cast<RegisterType>(cb::bit::Bit(bit_count - 1));
		}

		///
		/// @brief 获取位掩码。其中指定范围内的位为 1, 其他位为 0.
		/// 	@note 是一个左闭右开区间。
		///
		/// @param begin 起始索引。左端点是闭的。
		/// @param end 结束索引。右端点是开的。
		///
		/// @return
		///
		constexpr uint64_t BitMask(int begin, int end)
		{
			CheckBitRange<uint64_t>(begin, end);
			uint64_t ret = 0;
			for (int i = begin; i < end; i++)
			{
				ret |= Bit(i);
			}

			return ret;
		}

		/* #endregion */

		/* #region 置位 */

		///
		/// @brief 置位指定的位。
		///
		/// @param reg 寄存器。
		/// 	@note 其实就是普通的整型，只要是整型都可以。寄存器也可以强制转换成整型的指针，
		/// 	解引用后传进来。
		///
		/// @param bit_index 要置位的位的索引。
		///
		template <typename RegisterType>
		constexpr void SetBit(RegisterType &reg, int bit_index)
		{
			CheckBitIndex<RegisterType>(bit_index);
			reg |= Bit(bit_index);
		}

		///
		/// @brief 将指定范围内的位置位。
		///
		/// @param reg 寄存器。
		/// @param begin 要置位的区间起点。闭端点。
		/// @param end 要置位的区间终点。开端点。
		///
		template <typename RegisterType>
		constexpr void SetBits(RegisterType &reg, int begin, int end)
		{
			CheckBitRange<RegisterType>(begin, end);
			reg |= BitMask(begin, end);
		}

		/* #endregion */

		/* #region 复位 */

		///
		/// @brief 复位指定的位。
		///
		/// @param reg 寄存器。
		/// 	@note 其实就是普通的整型，只要是整型都可以。寄存器也可以强制转换成整型的指针，
		/// 	解引用后传进来。
		///
		/// @param bit_index 要复位的位的索引。
		///
		template <typename RegisterType>
		constexpr void ResetBit(RegisterType &reg, int bit_index)
		{
			CheckBitIndex<RegisterType>(bit_index);
			reg &= ~Bit(bit_index);
		}

		///
		/// @brief 将指定范围内的位复位（置成 0.）。
		///
		/// @param reg 寄存器。
		/// @param begin 要复位的区间起点。闭端点。
		/// @param end 要复位的区间终点。开端点。
		///
		template <typename RegisterType>
		constexpr void ResetBits(RegisterType &reg, int begin, int end)
		{
			CheckBitRange<RegisterType>(begin, end);
			reg &= ~BitMask(begin, end);
		}

		/* #endregion */

		/* #region 读位 */

		///
		/// @brief 读取指定位的值。
		///
		/// @param reg 寄存器。
		/// @param bit_index 要读取的位的索引。
		///
		/// @return
		///
		template <typename RegisterType>
		constexpr bool ReadBit(RegisterType const &reg, int bit_index)
		{
			CheckBitIndex<RegisterType>(bit_index);
			return reg & Bit(bit_index);
		}

		///
		/// @brief 读取指定范围内的位。
		/// 	@note 读取后会将取出的这些位移动到与最低位对齐。
		///
		/// @param reg
		/// @param begin
		/// @param end
		/// @return
		///
		template <typename RegisterType>
		constexpr RegisterType ReadBits(RegisterType const &reg, int begin, int end)
		{
			CheckBitRange<RegisterType>(begin, end);
			RegisterType ret = reg & BitMask(begin, end);
			ret >>= begin;
			return ret;
		}

		/* #endregion */

		/* #region 写位 */

		///
		/// @brief 向指定索引的位写入值。
		///
		/// @param reg
		/// @param bit_index
		/// @param value
		/// @return
		///
		template <typename RegisterType>
		constexpr void WriteBit(RegisterType &reg, int bit_index, bool value)
		{
			CheckBitIndex<RegisterType>(bit_index);
			if (value)
			{
				SetBit(reg, bit_index);
			}
			else
			{
				ResetBit(reg, bit_index);
			}
		}

		///
		/// @brief 将值写入寄存器指定的位范围。
		///
		/// @param reg 寄存器。
		/// @param begin 位范围起始。闭端点。
		/// @param end 位范围结束。开端点。
		/// @param value 要写入 reg 的指定范围内的值。
		///
		template <typename RegisterType>
		constexpr void WriteBits(RegisterType &reg, int begin, int end, uint64_t value)
		{
			CheckBitRange<RegisterType>(begin, end);

			// 将值移位，与要写入的寄存器位置对齐。
			value <<= begin;
			uint64_t bit_mask = cb::bit::BitMask(begin, end);
			value &= bit_mask;

			// 将要写入的范围先清零
			reg &= ~bit_mask;

			// 通过按位或运算写入这些位。
			reg |= value;
		}

		/* #endregion */

		/* #region 地址对齐 */

		///
		/// @brief 将 address 向上调整到 align_byte_count 字节对齐的地址。
		///
		/// @param address
		/// @param align_byte_count
		/// @return
		///
		template <typename AddressType>
		constexpr AddressType AlignUp(AddressType address, size_t align_byte_count = 8)
		{
			size_t size = reinterpret_cast<size_t>(address);
			size_t mod = size % align_byte_count;
			size_t aligned_size = (size / align_byte_count) * align_byte_count;
			if (mod > 0)
			{
				aligned_size += align_byte_count;
			}

			return reinterpret_cast<AddressType>(aligned_size);
		}

		///
		/// @brief 将 address 向下调整到 align_byte_count 字节对齐的地址。
		///
		/// @param address
		/// @param align_byte_count
		/// @return
		///
		template <typename AddressType>
		constexpr AddressType AlignDown(AddressType address, size_t align_byte_count = 8)
		{
			size_t size = reinterpret_cast<size_t>(address);
			size_t aligned_size = (size / align_byte_count) * align_byte_count;
			return reinterpret_cast<AddressType>(aligned_size);
		}

		///
		/// @brief 获取指定类型的对齐后的大小。
		///
		/// @return
		///
		template <typename T, size_t AlignByteCount = 8>
		constexpr size_t GetAlignedSize()
		{
			return cb::bit::AlignUp(sizeof(T), AlignByteCount);
		}

		/* #endregion */

	} // namespace bit
} // namespace cb
