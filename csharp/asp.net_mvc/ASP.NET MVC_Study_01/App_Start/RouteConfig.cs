﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;

namespace ASP.NET_MVC_Study_01
{
    public class RouteConfig
    {
        public static void RegisterRoutes(RouteCollection routes)
        {
            routes.IgnoreRoute("{resource}.axd/{*pathInfo}");

            routes.MapRoute(
                name: "Default",
                url: "{controller}/{action}/{*values}",
                defaults: new { controller = "Home", action = "About" }
            );

            //routes.MapRoute(
            //    name: "1",
            //    url: "{*values}",
            //    defaults: new { controller = "Home", action = "About" } 
            //);
        }
    }
}
