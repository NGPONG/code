using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace AJAX_Demo
{
    public partial class UserInfo : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        /// <summary>
        /// Thread Ways Apply My Theme
        /// </summary>
        /// <param name="sender">Page</param>
        /// <param name="e">EventArgs</param>
        protected void Page_PreInit(object sender, EventArgs e)
        {
            HttpCookieCollection collection = base.Request.Cookies;
        }
    }
}