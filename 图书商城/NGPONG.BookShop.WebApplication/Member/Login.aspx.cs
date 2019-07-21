using NGPONG.BookShop.BLL;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Script.Serialization;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace NGPONG.BookShop.WebApplication.Member
{
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string flag = new Articel_WordsService().CheckReplace("123");


            /* 针对用户在需要校验Session的页面中，如果Session过期了则跳转回登陆页面，这时候就看用户是否还保有Cookie，如果有的话再直接跳转回最开始的页面 */
            if (IsCookieEffective())
            {
                BLL.UsersService usersService = new BLL.UsersService();

                Model.Users users = new Model.Users() { LoginId = Request.Cookies["cp1"].Value, LoginPwd = Request.Cookies["cp2"].Value };
                var userInfo = usersService.GetUserInfo(users);

                // Cookie是有效的，直接跳转
                if (userInfo.Count > 0)
                {
                    // 重新写入Session
                    base.Session["UserInfo"] = userInfo[0];

                    /*
                    验证当前页面是否是需要重返上一个页面的
                    如果有需要是会带有RedirectUrl的参数的
                    */

                    // 如果不是的话，并且用户已经有Cookie了并且是有效的，则跳转到主页
                    if (string.IsNullOrEmpty(base.Request.QueryString["RedirectUrl"]))
                    {
                        base.Response.Redirect("/Member/Default.aspx");
                    }
                    else
                    {
                        base.Response.Redirect(base.Request.QueryString["RedirectUrl"]?.ToString());
                    }
                }
            }
        }

        protected bool IsCookieEffective()
        {
            bool flag = false;
            // 如果用户存在Cookie，则判断Cookie是否为有效用户名和密码，如果是的话直接返回上一个页面
            if (Request.Cookies["cp1"] != null && Request.Cookies["cp2"] != null)
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
            return flag;
        }
    }
}
