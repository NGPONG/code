using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace 省市联动
{
    public partial class index : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack)
            {
                base.Response.Write("I am PageLoad");
            }
        }

        protected void Page_LoadViewState(object sender, EventArgs e)
        {
            string str = "321";
        }


        protected void Page_PostBackdata(object sender, EventArgs e)
        {
            string str = "321";
        }

        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
        {
            base.Response.Write(base.Request.Form["DropDownList1"]);
        }
    }
}