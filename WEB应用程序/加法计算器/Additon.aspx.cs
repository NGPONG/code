using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace 加法计算器
{
    public partial class Additon : System.Web.UI.Page
    {
        protected int strResult;
        protected int txtNumSpecial1Count { get; set; }
        protected int txtNumSpecial2Count { get; set; }
        protected void Page_Load(object sender, EventArgs e)
        {
            if (base.IsPostBack)
            {
                //strResult = Convert.ToInt32(base.Request.Form["txtNumSpecial1"].ToString()) + Convert.ToInt32(base.Request.Form["txtNumSpecial2"].ToString());

                //base.ViewState["txtNumSpecial1Count"] = Convert.ToInt32(base.Request.Form["txtNumSpecial1"].ToString());
                //base.ViewState["txtNumSpecial2Count"] = Convert.ToInt32(base.Request.Form["txtNumSpecial2"].ToString());

                //this.txtNumSpecial1Count = Convert.ToInt32(base.ViewState["txtNumSpecial1Count"]);
                //this.txtNumSpecial2Count = Convert.ToInt32(base.ViewState["txtNumSpecial2Count"]);

            }
        }
    }
}