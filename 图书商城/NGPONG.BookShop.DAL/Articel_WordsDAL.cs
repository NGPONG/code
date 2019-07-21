using NGPONG.BookShop.Common.Helper;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Caching;

namespace NGPONG.BookShop.DAL
{
    public class Articel_WordsDAL
    {
        public void GetArticel_Words()
        {
            List<Articel_Words> articel_Words = SqlHelper.GetDataList<Articel_Words>("select * from Articel_Words");
            // 写入缓存
            CacheHelper.SetSafe("Articel_Words", articel_Words, Cache.NoAbsoluteExpiration);
        }
    }
}
