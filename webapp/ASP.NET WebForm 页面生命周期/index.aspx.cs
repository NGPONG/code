using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ASP.NET_WebForm_页面生命周期
{
    public partial class index : System.Web.UI.Page
    {
        protected void Page_PreInit(object sender, EventArgs e)
        {
            base.Response.Write("I Am Page_PreInit<br/>");
        }

        protected void Page_Init(object sender, EventArgs e)
        {
            base.Response.Write("I Am Page_Init<br/>");
        }
        protected void Page_InitComplete(object sender, EventArgs e)
        {
            base.Response.Write("I Am Page_InitComplete<br/>");
        }
        protected void Page_PreLoad(object sender, EventArgs e)
        {
            base.Response.Write("I Am Page_PreLoad<br/>");
        }
        protected void Page_Load(object sender, EventArgs e)
        {
            base.Response.Write("I Am Page_Load<br/>");
        }
        protected void Page_LoadComplete(object sender, EventArgs e)
        {
            base.Response.Write("I Am Page_LoadComplete<br/>");
        }
        protected void Page_PreRender(object sender, EventArgs e)
        {
            base.Response.Write("I Am Page_PreRender<br/>");
        }
        protected void Page_PreRenderComplete(object sender, EventArgs e)
        {
            base.Response.Write("I Am Page_PreRenderComplete<br/>");
        }
        protected void Page_SaveStateComplete(object sender, EventArgs e)
        {
            base.Response.Write("I Am Page_SaveStateComplete<br/>");
        }
        //protected void Page_Unload(object sender, EventArgs e)
        //{
        //    base.Response.Write("I Am Page_Unload<br/>");
        //}

        protected void Unnamed_Init(object sender, EventArgs e)
        {
            base.Response.Write("I Am Unnamed_Init<br/>");
        }

    }
}