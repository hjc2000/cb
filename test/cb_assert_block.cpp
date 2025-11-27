#include "base/string/define.h"
#include "cb/cb_define.h"
#include <stdexcept>

void cb_assert_block()
{
	throw std::runtime_error{CODE_POS_STR + "断言失败。"};
}
