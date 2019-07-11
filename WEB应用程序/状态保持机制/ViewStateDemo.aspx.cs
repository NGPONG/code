using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace 状态保持机制
{
    public partial class ViewStateDemo : System.Web.UI.Page
    {
        protected int ValueAdd { get; set; }

        protected void Page_Load(object sender, EventArgs e)
        {
            if (base.ViewState["value"] == null)
            {
                base.ViewState.Add("value", 0);
            }
            else
            {
                this.ValueAdd = Convert.ToInt32(base.ViewState["value"].ToString());
                this.ValueAdd++;
                //base.ViewState["value"] = this.ValueAdd;
            }
        }
    }
}