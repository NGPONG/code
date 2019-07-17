using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Web;
using System.Linq;
using System.Web.Security;
using System.Web.SessionState;
using System.Text.RegularExpressions;

namespace NGPONG.BookShop.WebApplication
{
    public class Global : System.Web.HttpApplication
    {

        protected void Application_Start(object sender, EventArgs e)
        {

        }

        protected void Session_Start(object sender, EventArgs e)
        {

        }

        protected void Application_BeginRequest(object sender, EventArgs e)
        {
            // URL重写

            // 获取当前请求资源的虚拟路径，并且以"~"作为开头，如：~/Member/Booklist_1.aspx
            string url = Request.AppRelativeCurrentExecutionFilePath;

            Match match = Regex.Match(url, @"~/Member/BookList_([a-zA-Z0-9_-]).aspx");
            if (match.Success)
            {
                Context.RewritePath("~/Member/BookList.aspx?PaginalNumber=" + match.Groups[1].Value);
            }
        }

        protected void Application_AuthenticateRequest(object sender, EventArgs e)
        {

        }

        protected void Application_Error(object sender, EventArgs e)
        {

        }

        protected void Session_End(object sender, EventArgs e)
        {

        }

        protected void Application_End(object sender, EventArgs e)
        {

        }
    }
}