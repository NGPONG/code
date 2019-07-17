using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Web;
using System.Web.Caching;

namespace NGPONG.BookShop.Common.Helper
{
    public static class CacheHelper
    {
        // 锁实例
        private static object objLock = new object();

        public static object Get(string key)
        {
            return HttpRuntime.Cache[key];
        }
        public static void Set(string key, object value)
        {
            HttpRuntime.Cache[key] = value;
        }
        public static void Set(string key, object value, DateTime time)
        {
            HttpRuntime.Cache.Insert(key, value, null, time, Cache.NoSlidingExpiration);
        }
        public static void SetSafe(string key, object value, DateTime time)
        {
            if (HttpRuntime.Cache[key] == null)
            {
                if (Monitor.IsEntered(objLock))
                {
                    Thread.Sleep(100);
                    // 递归
                    SetSafe(key, value, time);
                }

                lock (objLock)
                {
                    Set(key, value, time);
                }
            }
        }
        public static void Remove(string key)
        {
            HttpRuntime.Cache.Remove(key);
        }
    }
}
