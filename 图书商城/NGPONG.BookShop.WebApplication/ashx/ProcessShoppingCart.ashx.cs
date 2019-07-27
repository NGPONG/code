using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using NGPONG.BookShop.BLL;
using NGPONG.BookShop.Common.Unitis;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Routing;
using System.Web.Script.Serialization;
using System.Web.SessionState;

namespace NGPONG.BookShop.WebApplication.ashx
{
    /// <summary>
    /// ProcessShoppingCart 的摘要说明
    /// </summary>
    public class ProcessShoppingCart : IHttpHandler, IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            // 获取通过Cookie所存放的购物车内容
            var cookieRequestExpando = JsonConvert.DeserializeObject<JArray>(context.Request.Cookies["shoppingCart"]?.Value ?? string.Empty);

            // 获取此次所提交的需要存放到购物车的内容
            var productInfo = JsonConvert.DeserializeObject<JObject>(context.Request.Form["productInfo"] ?? string.Empty);

            if (productInfo == null)
            {
                context.Response.Write(JsonDynamic.ToJson(new
                {
                    IsSuccess = false,
                    Message = "提交信息错误!",
                    Status = "500"
                }));
                context.Response.End();
            }

            string action = context.Request.Form["Action"];

            // 添加：手动点击添加至购物车或通过在购物车页面上的+-号进行添加
            if (action == "Add")
            {
                /*
                   离线状态：把此次所提交的购物车内容继续存放到Cookie返回给Client
                   在线状态：把此次所提交的内容加所提交的Cookie所存放的购物车内容扔进数据库，并且清空Cookie所存放的购物车内容
                */
                if (context.Session["UserInfo"] != null)
                {
                    // 如果有Cookie提交上来，证明用户之前是在未登录状态下添加的购物车信息
                    if (cookieRequestExpando != null)
                    {
                        // 先把本次POST过来的数据加入到Cookie Cart集合中
                        ProcessCartCookieExpando(cookieRequestExpando, productInfo);

                        CartService cartService = new CartService();

                        // 添加信息
                        foreach (var jToken in cookieRequestExpando)
                        {
                            dynamic obj = new
                            {
                                UserId = (context.Session["UserInfo"] as Model.Users).Id,
                                BookId = jToken.Value<string>("bookId"),
                                Count = jToken.Value<int>("qty")
                            };
                            cartService.AddCart(obj);
                        }

                        // 清除Cookie
                        HttpCookie cookie = new HttpCookie("shoppingCart");
                        cookie.Expires = DateTime.Now.AddDays(-1);
                        context.Response.Cookies.Add(cookie);
                    }
                    else
                    {
                        CartService cartService = new CartService();

                        // 添加信息
                        cartService.AddCart(new
                        {
                            UserId = (context.Session["UserInfo"] as Model.Users).Id,
                            BookId = Convert.ToString(productInfo["bookId"]),
                            Count = Convert.ToInt32(productInfo["qty"])
                        });
                    }
                }
                else
                {
                    HttpCookie cookie;
                    if (cookieRequestExpando != null)
                    {
                        // 先把本次POST过来的数据加入到Cookie Cart集合中
                        ProcessCartCookieExpando(cookieRequestExpando, productInfo);

                        cookie = new HttpCookie("shoppingCart", JsonConvert.SerializeObject(cookieRequestExpando));
                        cookie.Expires = DateTime.Now.AddDays(7);
                    }
                    else
                    {
                        cookie = new HttpCookie("shoppingCart", JsonConvert.SerializeObject(new object[] { productInfo }));
                        cookie.Expires = DateTime.Now.AddDays(7);
                    }

                    context.Response.Cookies.Add(cookie);
                }

                context.Response.Write(JsonDynamic.ToJson(new
                {
                    IsSuccess = true,
                    Message = "商品已成功添加至购物车当中!",
                    Status = "200"
                }));
            }
            else if (action == "Delete")
            {
                if (context.Session["UserInfo"] != null)
                {
                    if (cookieRequestExpando != null)
                    {
                        // 添加信息
                        foreach (var jToken in cookieRequestExpando)
                        {
                            dynamic obj = new
                            {
                                UserId = (context.Session["UserInfo"] as Model.Users).Id,
                                BookId = jToken.Value<string>("bookId"),
                                Count = jToken.Value<int>("qty")
                            };
                            new CartService().AddCart(obj);
                        }

                        // 清除Cookie
                        HttpCookie cookie = new HttpCookie("shoppingCart");
                        cookie.Expires = DateTime.Now.AddDays(-1);
                        context.Response.Cookies.Add(cookie);
                    }

                    new CartService().DeleteCart((context.Session["UserInfo"] as Model.Users).Id, productInfo["bookId"].ToString());
                }
                else
                {
                    var query = cookieRequestExpando.Where(x => x["bookId"].ToString() == productInfo["bookId"].ToString());
                    if (query.Count() == 0)
                    {
                        context.Response.Write(JsonDynamic.ToJson(new
                        {
                            IsSuccess = false,
                            Message = "提交信息错误!",
                            Status = "500"
                        }));
                        context.Response.End();
                    }
                    else
                    {
                        cookieRequestExpando.Remove(query.First());

                        // 防止继续写入空数据
                        if (cookieRequestExpando.Count == 0)
                        {
                            // 清除Cookie
                            HttpCookie cookie = new HttpCookie("shoppingCart");
                            cookie.Expires = DateTime.Now.AddDays(-1);
                            context.Response.Cookies.Add(cookie);
                        }
                        else
                        {
                            // 重新写入Cookie
                            HttpCookie cookie = new HttpCookie("shoppingCart", JsonConvert.SerializeObject(cookieRequestExpando));
                            cookie.Expires = DateTime.Now.AddDays(7);
                            context.Response.Cookies.Add(cookie);
                        }
                    }
                }

                context.Response.Write(JsonDynamic.ToJson(new
                {
                    IsSuccess = true,
                    Message = "删除成功!",
                    Status = "200"
                }));
            }
            else if (action == "Update")
            {
                if (context.Session["UserInfo"] != null)
                {
                    if (cookieRequestExpando != null)
                    {
                        // 添加信息
                        foreach (var jToken in cookieRequestExpando)
                        {
                            dynamic obj = new
                            {
                                UserId = (context.Session["UserInfo"] as Model.Users).Id,
                                BookId = jToken.Value<string>("bookId"),
                                Count = jToken.Value<int>("qty")
                            };
                            new CartService().AddCart(obj);
                        }

                        // 清除Cookie
                        HttpCookie cookie = new HttpCookie("shoppingCart");
                        cookie.Expires = DateTime.Now.AddDays(-1);
                        context.Response.Cookies.Add(cookie);
                    }

                    new CartService().UpdateCart((context.Session["UserInfo"] as Model.Users).Id, productInfo["bookId"].ToString(), Convert.ToInt32(productInfo["qty"]));
                }
                else
                {
                    // 更新数量
                    var activeBookInfo = cookieRequestExpando.Where(x => x["bookId"].ToString() == productInfo["bookId"].ToString()).First()["qty"] = productInfo["qty"].ToString();

                    // 重新写入Cookie
                    HttpCookie cookie = new HttpCookie("shoppingCart", JsonConvert.SerializeObject(cookieRequestExpando));
                    cookie.Expires = DateTime.Now.AddDays(7);
                    context.Response.Cookies.Add(cookie);
                }

                context.Response.Write(JsonDynamic.ToJson(new
                {
                    IsSuccess = true,
                    Message = "修改成功!",
                    Status = "200"
                }));
            }
            else
            {
                context.Response.Write(JsonDynamic.ToJson(new
                {
                    IsSuccess = false,
                    Message = "提交信息错误!",
                    Status = "500"
                }));
                context.Response.End();
            }
        }
        public void ProcessCartCookieExpando(JArray cookieRequestExpando,JObject productInfo)
        {
            // 检查是否已经存在
            bool isUpdate = false;
            foreach (var item in cookieRequestExpando)
            {
                if (item["bookId"].ToString() == productInfo["bookId"].ToString())
                {
                    isUpdate = true;
                    item["qty"] = (Convert.ToInt32(item["qty"]) + Convert.ToInt32(productInfo["qty"])).ToString();
                    break;
                }
            }
            // 如果还没有更新则代表无相同项
            if (!isUpdate)
            {
                cookieRequestExpando.Add(productInfo);
            }
        }
        public bool IsReusable
        {
            get
            {
                return false;
            }
        }
    }
}