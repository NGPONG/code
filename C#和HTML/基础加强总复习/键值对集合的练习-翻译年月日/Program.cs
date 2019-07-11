using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 键值对集合的练习_翻译年月日
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<char, char> dic = new Dictionary<char, char>();
            string str = "1一--2二--3三--4四--5五--6六--7七--8八--9九--0零";
            string[] strTemp = str.Split(new char[] { '-' }, StringSplitOptions.RemoveEmptyEntries);

            for (int i = 0; i < strTemp.Length; i++)
            {
                dic.Add(strTemp[i][1], strTemp[i][0]);
            }

            string year = string.Empty;
            string month = string.Empty;
            string day = string.Empty;

            Console.WriteLine("请输入日期");
            string date = Console.ReadLine();
            string yearJudgeMent = date.Substring(0, date.IndexOf('年')+1);
            string monthJudgeMent = date.Substring(date.IndexOf('年'), (date.IndexOf('月')+1)-date.IndexOf('年'));
            string dayJudgeMent = date.Substring(date.IndexOf('月'));
            
            //判断年份
            for (int i = 0; i < yearJudgeMent.Length; i++)
            {
                if (dic.ContainsKey(yearJudgeMent[i]))
                {
                    year += dic[yearJudgeMent[i]].ToString();
                }
            }

            //判断月份
            for (int i = 0; i < monthJudgeMent.Length; i++)
            {
                if (monthJudgeMent.Contains("十")&& monthJudgeMent[i] == '十')
                {
                    if (monthJudgeMent[i - 1] == '年')
                    {
                        if (monthJudgeMent[i + 1] == '月')
                        {
                            month = "年10";
                        }
                        else if (dic.ContainsKey(monthJudgeMent[i + 1]))
                        {
                            month = "年" + dic['一'].ToString() + dic[monthJudgeMent[i + 1]].ToString();
                        }
                    }
                }
                else if(!monthJudgeMent.Contains("十"))
                {
                    for (int n= 0; n < monthJudgeMent.Length; n++)
                    {
                        if (dic.ContainsKey(monthJudgeMent[n])) 
                        {
                            month += dic[monthJudgeMent[n]].ToString();
                        }
                        else
                        {
                            if (monthJudgeMent[n] == '月') 
                            {
                                break;
                            }
                            month += monthJudgeMent[n].ToString();
                        }
                    }
                    break;
                }
            }

            //判断日期  月八日
            for (int i = 0; i < dayJudgeMent.Length; i++)
            {
                if (dayJudgeMent.Contains("十") && dayJudgeMent[i] == '十') 
                {
                    if (dic.ContainsKey(dayJudgeMent[i - 1])) 
                    {
                        if (dic.ContainsKey(dayJudgeMent[i + 1])) 
                        {
                            day = "月" + dic[dayJudgeMent[i - 1]].ToString() + dic[dayJudgeMent[i + 1]].ToString() + "日";
                        }
                        else if (dayJudgeMent[i + 1] == '日')
                        {
                            day = "月" + dic[dayJudgeMent[i - 1]].ToString() + "0日";
                        }
                    }
                    else if (dayJudgeMent[i - 1] == '月') 
                    {
                        if (dayJudgeMent[i + 1] == '日') 
                        {
                            day = "月" + dic['一'].ToString() + "0日";
                        }
                        else if (dic.ContainsKey(dayJudgeMent[i + 1])) 
                        {
                            day = "月" + dic['一'].ToString() + dic[dayJudgeMent[i + 1]].ToString() + "日";
                        }
                    }
                }
                else if (!dayJudgeMent.Contains("十")) 
                {
                    for (int n = 0; n < dayJudgeMent.Length; n++)
                    {
                        if (dic.ContainsKey(dayJudgeMent[n]))
                        {
                            day += dic[dayJudgeMent[n]].ToString();
                        }
                        else 
                        {
                            day += dayJudgeMent[n].ToString();
                        }
                    }
                    break;
                }
            }
            date = year + month + day;
            Console.WriteLine(date);
            Console.ReadLine();
        }
    }
}
