#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <stack>
#include <list>
#include <ranges>
#include <string_view>
#include <algorithm>
#include <random>
#include <cstring>
#include <regex>
#include <chrono>

#include "product.hpp"
#include "zip.hpp"

using SET_STR = std::set<std::string>;
using VEC_STR = std::vector<std::string>;
using VEC_VEC_STR = std::vector<VEC_STR>;

inline auto Split2Set(const std::string& data, const std::string& delimeter = ",") -> std::set<std::string>
{
    if (data.empty() || delimeter.empty())
        return {};

    auto view = data | std::views::split(delimeter.front())
        | std::views::transform([](auto&& ele) { return std::string_view(&*ele.begin(), std::ranges::distance(ele)); });

    return { view.begin(), view.end() };
};
inline auto Split2Vec(const std::string& data, const std::string& delimeter = ",") -> std::vector<std::string>
{
    if (data.empty() || delimeter.empty())
        return {};

    auto view = data | std::views::split(delimeter.front())
        | std::views::transform([](auto&& ele) { return std::string_view(&*ele.begin(), std::ranges::distance(ele)); });

    return { view.begin(), view.end() };
};
inline bool SplitByArray(const std::string& data, VEC_STR& vs, const std::string& delimeter = ",")
{
    if (data.empty() || delimeter.empty())
        return false;

    auto view = data | std::views::split(delimeter.front())
        | std::views::transform([](auto&& ele) { return std::string_view(&*ele.begin(), std::ranges::distance(ele)); });

    for (const auto& str : view)
        vs.push_back(std::string(str));

    return true;
};
inline bool SplitByGroups(const std::string& data, VEC_VEC_STR& vec, const std::string& outerDelimeter = ";", const std::string& innerDelimeter = ",")
{
    if (data.empty() || outerDelimeter.empty() || innerDelimeter.empty())
        return false;

    auto outerViews = data | std::views::split(outerDelimeter.front())
        | std::views::transform([](auto&& ele) { return std::string_view(&*ele.begin(), std::ranges::distance(ele)); });

    for (const auto& str : outerViews)
        vec.push_back(Split2Vec(std::string(str), innerDelimeter));

    return true;
};

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

template <typename Range, typename Value = typename Range::value_type>
std::string FullJoin(const Range& range, const std::string& delimiter)
{
    std::ostringstream os;

    auto b = begin(range), e = end(range);

    if (b != e) 
    {
        std::copy(b, std::prev(e), std::ostream_iterator<Value>(os, delimiter.c_str()));
        b = std::prev(e);
    }
    if (b != e) {
        os << *b;
    }

    return os.str();
}

bool IsCombineableParms(const VEC_STR& orignal, const VEC_STR& target, const int32_t combineIdx)
{
    auto isValidIndex  = [] (const int32_t idx)
    {
        return idx >= 0;
    };

    auto isValidSize   = [] (const int32_t idx, const int32_t orignalSize, const int32_t targetSize) 
    {
        return orignalSize == targetSize && (idx < orignalSize && idx < targetSize);;
    };

    auto isDigitalParm = [] (const std::string& parm)
    {
        return std::regex_match(parm, std::regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?")));
    };

    if (!isValidIndex(combineIdx)) 
    {
        return false;
    }

    if (!isValidSize(combineIdx, orignal.size(), target.size())) 
    {
        return false;
    }

    if (!isDigitalParm(orignal[combineIdx]) || !isDigitalParm(target[combineIdx])) 
    {
        return false;
    }

    return true;
}

int32_t main(void) {
  VEC_VEC_STR vvs;
  // //SplitByGroups("1000;Gold", vvs);
  SplitByGroups("hahahah,okkkkk,wtf!!;1200;1,2,3,4;ok,NGPONG", vvs);
  // // vvs.push_back({ "hahahah", "okkkkk", "wtf!!" });
  // // vvs.push_back({ "1200" });
  // // vvs.push_back({ "1", "2", "3", "4" });
  // // vvs.push_back({ "OK", "NGPONG" });

  auto result = VEC_STR{};
  for (auto& vs : vvs) 
  {
      if (result.empty())
      {
          result = std::move(vs);
      }
      else
      {
          auto tmp = VEC_STR{};
          for (auto&& [parm1, parm2] : cartesian_product(result, vs))
          {
              tmp.emplace_back(parm1 + "," + parm2);
          }

          result.swap(tmp);
      }
  }
  // for (auto it = vvs.begin(); it != vvs.end();)
  // {
  //     if (result.empty())
  //     {
  //         result = std::move(*it);
  //     }
  //     else
  //     {
  //         auto tmp = VEC_STR{};
  //         for (auto&& [parm1, parm2] : cartesian_product(result, *it))
  //         {
  //             tmp.emplace_back(parm1 + "," + parm2);
  //         }

  //         result.swap(tmp);
  //     }

  //     it = vvs.erase(it);
  // }

  auto ret = std::vector<VEC_STR>{};
  for (auto it = result.begin(); it != result.end(); ++it)
  {
      ret.emplace_back(Split2Vec(*it));
  }

  // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  // std::shuffle(ret.begin(), ret.end(), std::default_random_engine { seed });

  for (auto& ele : ret) {
    std::cout << FullJoin(ele, ",") << std::endl;
  }

  int32_t combine_idx = 2;
  auto cmp = [=] (const auto& lhs, const auto& rhs)
  {
        if (combine_idx > 0 && combine_idx < lhs.size() && combine_idx < rhs.size())
        {
            std::size_t idx = 0;

            for (auto&& [lele, rele] : zip(lhs, rhs))
            {
                if (idx++ == combine_idx)
                {
                    continue;
                }

                if (lele < rele)
                {
                    return true;
                }

                if (lele > rele)
                {
                    return false;
                }
            }
        }

        return false;
  };

  std::cout << "==========================================" << std::endl;

  auto groups = std::map<int32_t, std::vector<VEC_STR>>{};
  groups[combine_idx].insert(groups[combine_idx].end(), std::make_move_iterator(ret.begin()), 
                                                        std::make_move_iterator(ret.end()));

  VEC_STR effects;
  for (auto& [combineIdx, parms] : groups)
  {
      std::sort(parms.begin(), parms.end(), cmp);
  
      for (auto left = parms.begin(), right = parms.begin(); right != parms.end(); )
      {
          auto& orignal = *left;
  
          right = std::upper_bound(left, parms.end(), *left, cmp);

          for (++left; left != right; ++left)
          {
              auto& target = *left;

              if (!IsCombineableParms(orignal, target, combineIdx))
              {
                  effects.push_back(Join(target, ","));
                  continue;
              }

              if (std::atoi(orignal[combineIdx].c_str()) < std::atoi(target[combineIdx].c_str()))
              {
                  orignal[combineIdx] = target[combineIdx];
                  continue;
              }
          }
  
          effects.push_back(Join(orignal, ","));
      }
  }

  for (auto& ele : effects) {
    std::cout << ele << std::endl;
  }

  // std::sort(new_result.begin(), new_result.end(), cmp);

  // std::cout << "-------------------------------" << std::endl;

  // for (auto& ele : new_result) {
  //   std::cout << std::get<0>(ele) << std::endl;
  // }

  // std::cout << "-------------------------------" << std::endl;

  // // wtf!!,1200,4,ok
  // // wtf!!,1200,4,NGPONG
  // // wtf!!,1200,3,ok
  // // wtf!!,1200,3,NGPONG
  // // wtf!!,1200,2,ok
  // // wtf!!,1200,2,NGPONG
  // // wtf!!,1200,1,ok
  // // wtf!!,1200,1,NGPONG
  // // okkkkk,1200,4,ok
  // // okkkkk,1200,4,NGPONG
  // // okkkkk,1200,3,ok
  // // okkkkk,1200,3,NGPONG
  // // okkkkk,1200,2,ok
  // // okkkkk,1200,2,NGPONG
  // // okkkkk,1200,1,ok
  // // okkkkk,1200,1,NGPONG
  // // hahahah,1200,4,ok
  // // hahahah,1200,4,NGPONG
  // // hahahah,1200,3,ok
  // // hahahah,1200,3,NGPONG
  // // hahahah,1200,2,ok
  // // hahahah,1200,2,NGPONG
  // // hahahah,1200,1,ok
  // // hahahah,1200,1,NGPONG

  // std::vector<std::string> new_new_result;
  // for (auto first = new_result.begin(), last = new_result.begin(); last != new_result.end(); )
  // {
  //     auto& lsplit = std::get<1>(*first);

  //     if (!std::regex_match(lsplit[combine_idx], std::regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?")))) {
  //       std::cout << "first cannot merge: " << std::get<0>(*first) << std::endl;

  //       new_new_result.push_back(std::get<0>(*first));

  //       last = ++first;
  //       continue;
  //     }

  //     // std::cout << "cur: " << parmNum << std::endl;

  //     last = std::upper_bound(first, new_result.end(), *first, cmp);
  //     for (++first; first != last; ++first) {
  //       auto& rsplit = std::get<1>(*first);

  //       if (!std::regex_match("", std::regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?")))) {
  //         std::cout << "second cannot merge: " << std::get<0>(*first) << std::endl;

  //         new_new_result.push_back(std::get<0>(*first));
  //         continue;
  //       }

  //       if (atoi(rsplit[combine_idx].c_str()) <= atoi(lsplit[combine_idx].c_str()))
  //       {
  //         continue;
  //       }

  //       lsplit[combine_idx] = rsplit[combine_idx];

  //       // std::cout << "find: " << *first << std::endl;

  //       // reward.SetRewardCount(reward.GetRewardCount() + first->GetRewardCount());
  //     }

  //     new_new_result.push_back(Join(lsplit, ","));
  // }

  // for (auto& ele : new_new_result) {
  //   std::cout << ele << std::endl;
  // }

}
