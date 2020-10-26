package com.example.demo;

import com.netflix.zuul.ZuulFilter;
import com.netflix.zuul.context.RequestContext;
import com.netflix.zuul.exception.ZuulException;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.servlet.http.HttpServletRequest;

public class global_access_filter extends ZuulFilter {
  private static Logger log = LoggerFactory.getLogger(global_access_filter.class);

  /* @breif 过滤器的类型，它决定过滤器在请求的哪个生命周期中执行。这里定义为pre，代表会在请求被路由之前执行 */
  @Override
  public String filterType() {
    return "pre";
  }

  /* @breif 过滤器的执行顺序 */
  @Override
  public int filterOrder() {
    return 0;
  }

  /* @breif 指定过滤器的范围 */
  @Override
  public boolean shouldFilter() {
    return true;
  }

  /* @breief 过滤器具体逻辑 */
  @Override
  public Object run() throws ZuulException {
    RequestContext ctx = RequestContext.getCurrentContext();
    HttpServletRequest request = ctx.getRequest();

    log.info("send {} request to {}", request.getMethod(), request.getRequestURL().toString());

    Object accessToken = request.getParameter("accessToken");
    if(accessToken == null) {
      log.warn("access token is empty");
      ctx.setSendZuulResponse(false);
      ctx.setResponseStatusCode(401);
      return null;
    }
    log.info("access token ok");
    return null;
  }
}
