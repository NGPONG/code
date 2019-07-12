using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace NGPONG.BookShop.WebApplication.test
{
    public partial class test_03 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack)
            {
                // 为了解决在进行一次submit后，刷新当前页面表单元素还会重复提交的问题
                Response.Redirect(Request.Url.ToString());
            }
        }
    }
}