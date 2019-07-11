using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Session实现验证码校验
{
    public class CheckUserLogin:System.Web.UI.Page
    {
        protected void Page_Init(object sender, EventArgs e)
        {
            if (Session["userName"] != null)
            {
                if (Request.RawUrl == "/UserInfo.aspx")
                {
                    return;
                }
                Response.Redirect("UserInfo.aspx");
            }
            else
            {
                if (Request.RawUrl == "/UserLogin.aspx")
                {
                    return;
                }
                else
                {
                    Response.Redirect("UserLogin.aspx");
                }
            }
        }
    }
}