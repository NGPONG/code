using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace TEST_10
{
    public class MyModule : IHttpModule
    {
        public static List<string> objMyModuleEventStr = new List<string>();

        public void Init(HttpApplication application)
        {
            application.BeginRequest += this.Application_BeginRequest;
            application.AuthenticateRequest += this.Application_AuthenticateRequest;
            application.PostAuthenticateRequest += this.Application_PostAuthenticateRequest;
            application.AuthorizeRequest += this.Application_AuthorizeRequest;
            application.PostAuthorizeRequest += this.Application_PostAuthorizeRequest;
            application.ResolveRequestCache += this.Application_ResolveRequestCache;
            application.PostResolveRequestCache += this.Application_PostResolveRequestCache;
            application.PostMapRequestHandler += this.Application_PostMapRequestHandler;
            application.AcquireRequestState += this.Application_AcquireRequestState;
            application.PostAcquireRequestState += this.Application_PostAcquireRequestState;
            application.PreRequestHandlerExecute += this.Application_PreRequestHandlerExecute;
            application.PostRequestHandlerExecute += this.Application_PostRequestHandlerExecute;
            application.ReleaseRequestState += this.Application_ReleaseRequestState;
            application.PostReleaseRequestState += this.Application_PostReleaseRequestState;
            application.UpdateRequestCache += this.Application_UpdateRequestCache;
            application.PostUpdateRequestCache += this.Application_PostUpdateRequestCache;
            application.LogRequest += this.Application_LogRequest;
            application.PostLogRequest += this.Application_PostLogRequest;
            application.EndRequest += this.Application_EndRequest;

            //var request = application.Context.Request;
        }

        private void Application_EndRequest(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【EndRequest】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【EndRequest】<br/>");
            //HttpApplication application = (HttpApplication)sender;

            //for (int i = 0; i < MyModule.objMyModuleEventStr.Count; i++)
            //{
            //    application.Response.Write(objMyModuleEventStr[i]);
            //}
        }

        private void Application_PostLogRequest(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【PostLogRequest】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【PostLogRequest】<br/>");
        }

        private void Application_LogRequest(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【LogRequest】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【LogRequest】<br/>");
        }

        private void Application_PostUpdateRequestCache(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【PostUpdateRequestCache】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【PostUpdateRequestCache】<br/>");
        }

        private void Application_UpdateRequestCache(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【UpdateRequestCache】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【UpdateRequestCache】<br/>");
        }

        private void Application_PostReleaseRequestState(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【PostReleaseRequestState】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【PostReleaseRequestState】<br/>");
        }

        private void Application_ReleaseRequestState(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【ReleaseRequestState】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【ReleaseRequestState】<br/>");
        }

        private void Application_PostRequestHandlerExecute(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【PostRequestHandlerExecute】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【PostRequestHandlerExecute】<br/>");
        }

        private void Application_PreRequestHandlerExecute(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【PreRequestHandlerExecute】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【PreRequestHandlerExecute】<br/>");
        }

        private void Application_AcquireRequestState(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【AcquireRequestState】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【AcquireRequestState】<br/>");
        }

        private void Application_PostAcquireRequestState(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【PostAcquireRequestState】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【PostAcquireRequestState】<br/>");
        }

        private void Application_PostMapRequestHandler(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【PostMapRequestHandler】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【PostMapRequestHandler】<br/>");
        }

        private void Application_PostResolveRequestCache(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【PostResolveRequestCache】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【PostResolveRequestCache】<br/>");
        }

        private void Application_ResolveRequestCache(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【ResolveRequestCache】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【ResolveRequestCache】<br/>");
        }

        private void Application_PostAuthorizeRequest(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【PostAuthorizeRequest】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【PostAuthorizeRequest】<br/>");
        }

        private void Application_AuthorizeRequest(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【AuthorizeRequest】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【AuthorizeRequest】<br/>");
        }

        private void Application_PostAuthenticateRequest(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【PostAuthenticateRequest】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【PostAuthenticateRequest】<br/>");
        }

        private void Application_AuthenticateRequest(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.Write("HttpModule【AuthenticateRequest】<br/>");
            //MyModule.objMyModuleEventStr.Add("HttpModule【AuthenticateRequest】<br/>");
        }

        private void Application_BeginRequest(object sender, EventArgs e)
        {
            var application = sender as HttpApplication;
            application.Context.Response.End();
            //application.Context.Response.End();
            //MyModule.objMyModuleEventStr.Clear();
            //MyModule.objMyModuleEventStr.Add("HttpModule【BeginRequest】<br/>");
        }
        public void Dispose()
        {
        }
    }
}