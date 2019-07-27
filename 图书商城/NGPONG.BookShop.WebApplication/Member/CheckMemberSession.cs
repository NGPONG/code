using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.SessionState;

namespace NGPONG.BookShop.WebApplication.Member
{
    public class CheckMemberSession : System.Web.UI.Page
    {
        private bool _isRedirect;

        protected void Page_Init(object sender, EventArgs e)
        {
            if (Session["UserInfo"] == null)
            {
                // 如果Session过期了就要跳转回登陆页面
                if (_isRedirect)
                {
                    Common.Unitis.WebCommon.RedirectLogin();
                }
                else
                {
                    base.Response.Redirect("/Member/Login.aspx");
                }
            }
        }

        /// <summary>
        /// 构造器
        /// </summary>
        public CheckMemberSession(bool flag = true) { this._isRedirect = flag; }
    }
}