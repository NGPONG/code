using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Session实现验证码校验
{
    public partial class Error : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (base.Request.QueryString["errorString"] != null)
            {
                Session.Remove("verificationCode");
                Response.Write(base.Request.QueryString["errorString"]);
            }
        }
    }
}