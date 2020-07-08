using ASP.NET_MVC_Study_03.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ASP.NET_MVC_Study_03.Controllers
{
    public class TestController : Controller
    {
        [HttpGet]
        public ActionResult Index()
        {
            ViewData.Model = new CustomEntity() {

                Name = "WUPENG",
                Age  = 22
            };

            return View();
        }
    }
}