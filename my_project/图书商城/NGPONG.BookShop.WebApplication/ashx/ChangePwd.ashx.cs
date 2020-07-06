using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Script.Serialization;

namespace NGPONG.BookShop.WebApplication.ashx
{
    /// <summary>
    /// ChangePwd 的摘要说明
    /// </summary>
    public class ChangePwd : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            string emailInfo = context.Request.Cookies["emailInfo"].Value;
            if (emailInfo == null)
            {
                // Cookie失效
                context.Response.Write((new JavaScriptSerializer()).Serialize(new
                {
                    isSuccess = "false",
                    Message = "数据已过期!请重新修改密码"
                }));
            }

            Model.EmailInfo emailInfoModel = new JavaScriptSerializer().Deserialize(emailInfo, typeof(Model.EmailInfo)) as Model.EmailInfo;

            dynamic exp = HttpRuntime.Cache[$"{emailInfoModel.userName}EmailInfo"] as dynamic;
            if (emailInfoModel.userGuid == exp.userGuid && emailInfoModel.userName == exp.userName)
            {
                // 匹配成功
                HttpRuntime.Cache.Remove($"{emailInfoModel.userName}EmailInfo");
                HttpCookie cookie = new HttpCookie("emailInfo", "");
                cookie.Expires = DateTime.Now.AddDays(-1);
                context.Response.Cookies.Add(cookie);

                // 修改密码
                new BLL.UsersService().ChangekUserPwd(new Model.Users() { LoginId = emailInfoModel.userName, LoginPwd = Common.Unitis.WebCommon.GetMd5String(context.Request.Form["PwdNew"]) });

                context.Response.Write((new JavaScriptSerializer()).Serialize(new
                {
                    isSuccess = "true",
                    url = "\\Member\\Login.aspx"
                }));
            }
            else
            {
                context.Response.Write((new JavaScriptSerializer()).Serialize(new
                {
                    isSuccess = "false",
                    Message = "验证出错，请重新获取邮件在尝试"
                }));
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