#pragma once

namespace cb
{
	///
	/// @brief 利用负反馈的积分环节形成惯性环节。采用的是先对积分环节做差分近似，
	/// 然后用迭代形成闭环。
	///
	template <typename T>
	class FeedbackInertialElement
	{
	private:
		T _k_error = 0;
		T _feedback_div = 1;
		T _current_output = 0;

	public:
		FeedbackInertialElement(T const &k_error, T const &feedback_div)
		{
			_k_error = k_error;
			_feedback_div = feedback_div;
		}

		T KError() const
		{
			return _k_error;
		}

		void SetKError(T value)
		{
			_k_error = value;
		}

		T FeedbackDiv() const
		{
			return _feedback_div;
		}

		void SetFeedbackDiv(T value)
		{
			_feedback_div = value;
		}

		void ChangeParameter(T const &k_error, T const &feedback_div)
		{
			_k_error = k_error.Value();
			_feedback_div = feedback_div.Value();
		}

		///
		/// @brief 输入一个值，并获取反馈输出。
		///
		/// @param x
		///
		/// @return
		///
		T Input(T x)
		{
			T error = x - Feedback();
			_current_output += error * _k_error;
			return Feedback();
		}

		///
		/// @brief 反馈输出。
		///
		/// @return
		///
		T Feedback() const
		{
			return _current_output / _feedback_div;
		}

		///
		/// @brief 设置当前的反馈值。
		///
		/// @param value
		///
		/// @return
		///
		void SetFeedback(T value)
		{
			_current_output = value * _feedback_div;
		}

		///
		/// @brief 惯性时间常数
		///
		/// @param sample_interval
		///
		/// @return
		///
		T TimeConstant(T sample_interval)
		{
			//
			// 		k_error = (sample_interval * k) / T1
			// 		k_error = sample_interval * (k / T1)
			//
			// 则
			//
			// 		k / T1 = k_error / sample_interval
			// 		T1 / k = sample_interval / k_error
			//
			// 惯性时间常数为
			//
			// 		T1 / (k * kb)
			//		= (T1 / k) / kb
			//		= (T1 / k) * feedback_div
			//		= sample_interval / k_error * feedback_div
			//
			return sample_interval * _feedback_div / _k_error;
		}
	};

} // namespace cb
