using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Caching;
using System.Threading.Tasks;

namespace 缓存的使用
{
    public partial class index : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            #region 获取缓存的三种方式
            //// HttpContext.Cache
            //System.Web.Caching.Cache httpContext_Cache = HttpContext.Current.Cache;
            //// HttpRuntime.Cache
            //System.Web.Caching.Cache httpRuntime_Cache = HttpRuntime.Cache;
            //// Page.Cache
            //System.Web.Caching.Cache page_Cache = Page.Cache; //base.Cache 
            #endregion

            #region 添加缓存的三种方式
            //// 索引器：该方式是最直接的方式，其等价于Cache.Insert(string key, object value)
            //HttpRuntime.Cache["MyFirstAddCacheModule"] = "NGPONG";

            //// Insert：该方法提供了5种有效的重载，分别对应着该项缓存不同特性之间的声明，在该篇文档下面的节点中会逐一的说明
            //// 当缓存中已存在一个Insert函数所指定的键的是时候，Insert的做法则是把当前Insert的值覆盖到当前键所存储的值
            //HttpRuntime.Cache.Insert("MySecondAddCacheModule", "NGPONG");

            //// Add：该方法不太常用，因为在调用的过程当中必须声明完该项缓存的所有特性，不够灵活
            //// 当缓存中已存在一个aDD函数所指定的键的是时候，Add的做法则是继续为缓存容器中添加该键的值，这时候就会造成缓存键的重复问题
            //HttpRuntime.Cache.Add("MyThreadAddCacheModule", "NGPONG", null, Cache.NoAbsoluteExpiration, Cache.NoSlidingExpiration, CacheItemPriority.Normal, null);
            #endregion

            #region 设置缓存的过期时间策略

            //// 通过指定过期时间参数的值为【Cache.NoAbsoluteExpiration】来设置缓存的过期时间策略为滑动过期时间
            //HttpRuntime.Cache.Insert("MyCache", "NGPONG", null, Cache.NoAbsoluteExpiration, TimeSpan.FromSeconds(5));

            //// 通过指定过期时间参数的值为【Cache.NoAbsoluteExpiration】来设置缓存的过期时间策略为绝对过期时间
            //HttpRuntime.Cache.Insert("MyCache", "NGPONG", null, DateTime.Now.AddSeconds(5), Cache.NoSlidingExpiration);

            #endregion

            #region 设置缓存的移除优先级
            //// 设置缓存的移除优先级
            //HttpRuntime.Cache.Insert("MyCache", "NGPONG", null, Cache.NoAbsoluteExpiration, Cache.NoSlidingExpiration, CacheItemPriority.NotRemovable, null); 
            #endregion

            #region 移除指定项的缓存

            //// 如果缓存容器中并不存在所移除指定键的缓存的时候也不会抛异常
            //HttpRuntime.Cache.Remove("MyCache"); 

            #endregion

            #region 设置缓存移除通知回调
            //// 指定一个缓存移除通知，在该项缓存被移除后自动进行回调操作
            //// 需要注意的是，在进行回调的时候就不要操作【Request】和【Response】这两个类了，因为HttpContext并不在此次操作的上下文当中，如何理解这句话呢？我们第一次为这个页面发送了一个HTTP请求的时候，会调用Page_Load这个函数，并在这个函数中Insert了一个我们自定义的缓存，这时候会把结果Response回给Client，这时候HTTP协议的TCP通道就会关闭了，因为它不是长连接，所以这时候的HttpContext也就不在此次回调的上下文当中
            //HttpRuntime.Cache.Insert("MyCache", "NGPONG", null, DateTime.Now.AddSeconds(5), Cache.NoSlidingExpiration, CacheItemPriority.Normal, (string key, object value, CacheItemRemovedReason reason) =>
            // {
            //     // do something.....
            // });
            #endregion

            #region 缓存依赖于其他缓存
            //HttpRuntime.Cache.Insert("CacheB", "我是缓存B，我被缓存A依赖，当我发生改变的时候后会随之注销掉缓存A");

            //HttpRuntime.Cache.Insert("CacheA", "我是缓存A，我依赖于缓存B，当缓存B发生改变的时候我也会被注销掉", new CacheDependency(null, new string[] { "MyCacheDependency" }), Cache.NoAbsoluteExpiration, Cache.NoSlidingExpiration, CacheItemPriority.Normal, (string key, object value, CacheItemRemovedReason reason) =>
            //{
            //    if (reason == CacheItemRemovedReason.DependencyChanged)
            //    {
            //        // Do Something .....
            //    }
            //}); 
            #endregion

            #region 缓存依赖于文件
            //HttpRuntime.Cache.Insert("MyCacheDependecyFile", "NGPONG", new CacheDependency(@"C:\Users\NGPONG\Desktop\test.txt"), Cache.NoAbsoluteExpiration, Cache.NoSlidingExpiration, CacheItemPriority.Normal, (string key, object value, CacheItemRemovedReason reason) =>
            //{
            //    if (reason == CacheItemRemovedReason.DependencyChanged)
            //    {
            //        HttpRuntime.Cache.Insert("MyCacheDependecyFile", "哈哈我是新加入的缓存噢", new CacheDependency(@"C:\Users\NGPONG\Desktop\test.txt"));
            //    }
            //});
            #endregion
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            base.Response.Write(HttpRuntime.Cache["MyCacheDependecyFile"] == null ? "依赖文件被改变，我也被移除了" : HttpRuntime.Cache["MyCacheDependecyFile"].ToString());
        }
    }
}