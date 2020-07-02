using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebForm学习_01
{
    public partial class index : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            this.MyTextBox.Value = "123123123";
        }

        protected void btnShow_Click(object sender, EventArgs e)
        {
            string str;
            if (HttpContext.Current.Items["Something"] == null)
            {
                HttpContext.Current.Items["Something"] = "Items Test";
                str = "Items Test";
            }
            else
            {
                str = HttpContext.Current.Items["Something"].ToString();
            }
        }
    }
}