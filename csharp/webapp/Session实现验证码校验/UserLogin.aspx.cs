using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Session实现验证码校验
{
    public partial class UserLogin : CheckUserLogin
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack)
            {
                string verificationCode = Request.Form["verificationCode"];
                if (Session["verificationCode"] == null)
                {
                    Response.Redirect("Error.aspx?errorString=验证码已过期！请刷新");
                }
                if (!verificationCode.Equals(Session["verificationCode"].ToString(), StringComparison.InvariantCultureIgnoreCase))
                {
                    Response.Write("验证码已有误！请重新输入");
                    return;
                }

                string userName = Request.Form["userName"];
                if (string.IsNullOrEmpty(userName) || userName != "pengqi1997428")
                {
                    Response.Redirect("Error.aspx?errorString=无法找到当前用户！");
                }

                string userPwd = Request.Form["userPwd"];
                if (string.IsNullOrEmpty(userPwd) || userPwd != "kissyou199")
                {
                    Response.Redirect("Error.aspx?errorString=用户名或密码错误！");
                }

                // 已经登陆校验完，那验证码Session可以不用进行存储了
                Session.Remove("verificationCode");

                // 存储用户信息Session
                Session["userName"] = "pengqi1997428";
                Session.Timeout = 1;
                // 设置Cookie的过期时间
                HttpCookie cookie = new HttpCookie("ASP.NET_SessionId", Session.SessionID);
                cookie.Expires = DateTime.Now.AddDays(1);
                Response.Cookies.Add(cookie);

                Response.Redirect("UserInfo.aspx");
            }
        }

    }
}