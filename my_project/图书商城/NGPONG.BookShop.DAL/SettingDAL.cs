using NGPONG.BookShop.Common.Helper;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;
using System.Web.Caching;

namespace NGPONG.BookShop.DAL
{
    public class SettingDAL
    {
        public string GetSettingValue(string key)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@Name",key.Substring(key.IndexOf("_") + 1))
            };

            string scalarValue = SqlHelper.ExecuteScalar("select value from Settings where Name = @Name", parms)?.ToString();

            // 如果没查找到也要保存起来，并且设定一个相对较短的过期时间，预防缓存穿透的问题
            if (string.IsNullOrEmpty(scalarValue))
            {
                CacheHelper.SetSafe(key, scalarValue, DateTime.Now.AddSeconds(60));
            }
            else
            {
                CacheHelper.Set(key, scalarValue, Cache.NoAbsoluteExpiration);
            }

            return scalarValue;
        }
    }
}
