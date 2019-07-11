using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Session实现验证码校验
{
    public partial class UserInfo : CheckUserLogin
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Response.Write("欢迎回来！" + Session["userName"].ToString());
        }
    }
}