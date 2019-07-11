using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TEST_09
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string id = Session.SessionID;
            Session["123"] = "jaja";
            //Response.Cookies["ASP.NET_SessionId"].Expires = DateTime.Now.AddDays(1);
            // 合法
            // 
            //Response.Cookies["ASP.NET_SessionId"].Expires = DateTime.Now.AddDays(1);
            Response.Cookies["ASP.NET_SessionId"].Value = "3213123123";
            HttpCookieCollection cookieResponse = Response.Cookies;
            HttpCookieCollection cookieRequest = Request.Cookies;
        }
    }
}