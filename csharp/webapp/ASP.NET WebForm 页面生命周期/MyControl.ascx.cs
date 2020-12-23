using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ASP.NET_WebForm_页面生命周期
{
    public partial class MyControl : System.Web.UI.UserControl
    {
        public enum Theme
        {
            brown=10,
            green=20
        }
        private Theme _MyThemes;
        public Theme MyThemes
        {
            get
            {
                return this._MyThemes;
            }
            set
            {
                this._MyThemes = value;
            }
        }
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected override void LoadViewState(object savedState)
        {
            string str = string.Empty;
            base.LoadViewState(savedState);
        }
    }
}