using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace NGPONG.BookShop.WebApplication.Member
{
    public partial class Login : System.Web.UI.Page
    {
        /// <summary>
        /// 错误消息
        /// </summary>
        public string ErrorMessage { get; set; }

        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack)
            {
                
            }
        }


    }
}