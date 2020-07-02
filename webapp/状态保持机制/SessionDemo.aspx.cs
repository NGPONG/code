using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace 状态保持机制
{
    public partial class SessionDemo : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //string sessionid = base.Context.Session.SessionID;
            //base.Context.Session.Add("sessionTimeOutTest2", "傻逼玩意2");

            string id = base.Context.Session.SessionID;
            HttpCookie cookie = new HttpCookie("ASP.NET_SessionId", "哈哈哈哈哈沙雕沙雕沙雕");
            cookie.Expires = DateTime.Now.AddDays(1);
            base.Response.Cookies.Add(cookie);
        }
    }
}