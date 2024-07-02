#include <iostream>
#include <numeric>
#include <benchmark/benchmark.h>
#include <sstream>

#include "kwmsgshare.pb.h"

using SET_STR = std::set<std::string>;
using VEC_STR = std::vector<std::string>;
using VEC_VEC_STR = std::vector<VEC_STR>;

template<typename T>
std::string Join(const T& v, const std::string& delimiter)
{
    std::stringstream ss;
    for (const auto& element : v)
    {
        if (ss.rdbuf()->in_avail() != 0)
            ss << delimiter;
        ss << element;
    }
    return ss.str();
}

class KWMail
{
public:
    KWMail() {}

    KWMail(KWMail&&) = default;
    KWMail& operator=(KWMail&&) = default;

    KWMail(const KWMail&) = default;
    KWMail& operator=(const KWMail&) = default;

public:
    std::string ToString1(){
      VEC_STR strs;

      strs.push_back(this->mPromptId);
      strs.push_back(this->mTitle);
      strs.push_back(this->mContext);
      strs.push_back(this->mSender);
      strs.push_back(std::to_string(this->mCreateTs));

      return Join(strs, "#");
    }

    std::string ToString2(){

      KWMsg::MailInfo mail;
      mail.set_prompt_id(this->mPromptId);
      mail.set_title(this->mTitle);
      mail.set_context(this->mContext);
      mail.set_sender(this->mSender);
      mail.set_create_ts(this->mCreateTs);

      return mail.SerializeAsString();
    }

public:
    std::string mPromptId{""};    // 邮件配置ID
    std::string mTitle{""};       // 邮件标题
    std::string mContext{""};     // 邮件正文内容
    std::string mSender{""};      // 邮件发送者
    int64_t mCreateTs{0};        // 邮件创建时间戳
};

void foo_01(benchmark::State& state) {
  KWMail mail;
  
  mail.mPromptId = "123123123123";
  mail.mTitle = "123123123123";
  mail.mContext = "123123123123";
  mail.mSender = "123123123123";
  mail.mCreateTs = 1024;

  for (auto _: state) {
    std::string str = mail.ToString1();
  }
}
BENCHMARK(foo_01);

void foo_2(benchmark::State& state) {
  KWMail mail;
  
  mail.mPromptId = "123123123123";
  mail.mTitle = "123123123123";
  mail.mContext = "123123123123";
  mail.mSender = "123123123123";
  mail.mCreateTs = 1024;

  for (auto _: state) {
    std::string str = mail.ToString2();
  }
}
BENCHMARK(foo_2);

BENCHMARK_MAIN();
