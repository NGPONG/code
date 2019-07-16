using NGPONG.BookShop.DAL;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;

namespace NGPONG.BookShop.BLL
{
    public class SettingService
    {
        public string GetSettingValue(string key)
        {
            // 如果缓存不存在，则在数据库里面查询
            if (HttpRuntime.Cache[key] == null)
            {
                 new SettingDAL().GetSettingValue(key);
            }

            return HttpRuntime.Cache[key].ToString();
        }
    }
}
