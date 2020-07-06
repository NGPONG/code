using NGPONG.BookShop.Common.Helper;
using NGPONG.BookShop.DAL;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace NGPONG.BookShop.BLL
{
    public class Articel_WordsService
    {
        /// <summary>
        /// 检查禁用词
        /// </summary>
        /// <param name="msg"></param>
        /// <returns></returns>
        public bool CheckForbidMsg(string msg)
        {
            Articel_WordsDAL articel_WordsDAL = new Articel_WordsDAL();

            if (CacheHelper.Get("Articel_Words") == null)
            {
                articel_WordsDAL.GetArticel_Words();
            }

            string[] articel_Words = (CacheHelper.Get("Articel_Words") as List<Articel_Words>)
                                                    .Where<Articel_Words>(x => Convert.ToBoolean(x.IsForbid) == true)
                                                    .Select(x => x.WordPattern)
                                                    .ToArray<string>();

            string regex = string.Join("|", articel_Words);
            return Regex.IsMatch(msg, regex);
        }
        /// <summary>
        /// 检查审查词
        /// </summary>
        /// <param name="msg"></param>
        /// <returns></returns>
        public bool CheckModMsg(string msg)
        {
            Articel_WordsDAL articel_WordsDAL = new Articel_WordsDAL();

            if (CacheHelper.Get("Articel_Words") == null)
            {
                articel_WordsDAL.GetArticel_Words();
            }

            string[] articel_Words = (CacheHelper.Get("Articel_Words") as List<Articel_Words>)
                                                    .Where<Articel_Words>(x => Convert.ToBoolean(x.IsMod) == true)
                                                    .Select(x => x.WordPattern)
                                                    .ToArray<string>();

            string regex = string.Join("|", articel_Words);
            regex = regex.Replace(@"\", @"\\").Replace("{2}", @".{0,2}");
            return Regex.IsMatch(msg, regex);
        }
        /// <summary>
        /// 替换词过滤
        /// </summary>
        /// <returns></returns>
        public string CheckReplace(string msg)
        {
            Articel_WordsDAL articel_WordsDAL = new Articel_WordsDAL();

            if (CacheHelper.Get("Articel_Words") == null)
            {
                articel_WordsDAL.GetArticel_Words();
            }

            var articel_Words = (CacheHelper.Get("Articel_Words") as List<Articel_Words>)
                                                    .Where<Articel_Words>(x => !string.IsNullOrEmpty(x.ReplaceWord));
            
            foreach (Articel_Words item in articel_Words)
            {
                msg = msg.Replace(item.WordPattern, item.ReplaceWord);
            }

            return msg;
        }
    }
}
