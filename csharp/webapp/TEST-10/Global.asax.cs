using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.SessionState;

namespace TEST_10
{
    public class Global : System.Web.HttpApplication
    {

        /// <summary>
        /// 当Application Pool开始启动的时候会调用
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        protected void Application_Start(object sender, EventArgs e)
        {

        }

        protected void Session_Start(object sender, EventArgs e)
        {

        }

        protected void Application_BeginRequest(object sender, EventArgs e)
        {

        }

        protected void Application_AuthenticateRequest(object sender, EventArgs e)
        {
            MyModule.objMyModuleEventStr.Add("Global【AuthenticateRequest】<br/>");
        }

        /// <summary>
        /// 当异常信息在当前Application Pool中未进行有效的捕获的时候才会调用
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        protected void Application_Error(object sender, EventArgs e)
        {
            // 获取最后一次所引发的异常信息
            Exception ex = HttpContext.Current.Server.GetLastError();
        }

        protected void Session_End(object sender, EventArgs e)
        {

        }

        /// <summary>
        /// 当Application Pool关闭的时候才会调用
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        protected void Application_End(object sender, EventArgs e)
        {

        }

        protected void Application_EndRequest(object sender, EventArgs e)
        {
            string str = "123";
        }
    }
}