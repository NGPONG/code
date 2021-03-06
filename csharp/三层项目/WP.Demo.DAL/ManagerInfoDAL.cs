﻿using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SQLite;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WP.Demo.Common;
using WP.Demo.Model;

namespace WP.Demo.DAL
{
    public class ManagerInfoDAL
    {
        /// <summary>
        ///  获取数据
        /// </summary>
        /// <returns>序列化后的字节数组</returns>
        public List<byte[]> GetData()
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string sql = "select MId,MName,case MType when 0 then '经理' when 1 then '店员' end as MType from  ManagerInfo";

            try
            {
                DataTable dtTemp = SQLiteHelper.GetDataTable(sql);
                // 接受数据的数据模型类的集合
                List<ManagerInfoModel_GetData> listGetDataModel = new List<ManagerInfoModel_GetData>();
                for (int i = 0; i < dtTemp.Rows.Count; i++)
                {
                    listGetDataModel.Add(new ManagerInfoModel_GetData()
                    {
                        MId = Convert.ToInt32(dtTemp.Rows[i]["MId"]),
                        MName = Convert.ToString(dtTemp.Rows[i]["MName"]),
                        MType = Convert.ToString(dtTemp.Rows[i]["MType"])
                    });
                }
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<ManagerInfoModel_GetData>(listGetDataModel);

                return listSerializeBuff;
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, null, errMessage);
            }
        }
        /// <summary>
        ///  删除明细
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int DeleteManagerInfoDetail(ManagerInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MId = model.MId.ToString();

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MId",MId)
                };

            string sql = "DELETE FROM ManagerInfo WHERE MId = @MId";
            try
            {
                return SQLiteHelper.ExecuteNonQuery(sql, parms);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    errMessage = objException.InnerException.Message;
                    throw new Exception(objException.InnerException.Message);
                }
                errMessage = objException.Message;
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, parms, errMessage);
            }
        }
        /// <summary>
        ///  添加数据
        /// </summary>
        /// <param name="MName">用户名</param>
        /// <param name="MPwd">密码</param>
        /// <param name="MType">类型</param>
        /// <returns>受影响的行数</returns>
        public int AddManagerInfoDetail(ManagerInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MName = model.MName;
            string MPwd = model.MPwd;
            string MType = model.MType;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MName",MName),
                    new SQLiteParameter("@MPwd",MD5Encryption.GetEncryptionCharacter( MPwd)),
                    new SQLiteParameter("@MType",MType)
                };

            string sql = "insert into ManagerInfo(MName,MPwd,MType) values(@MName,@MPwd,@MType)";

            try
            {
                return SQLiteHelper.ExecuteNonQuery(sql, parms);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    errMessage = objException.InnerException.Message;
                    throw new Exception(objException.InnerException.Message);
                }
                errMessage = objException.Message;
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, parms, errMessage);
            }
        }
        /// <summary>
        ///  修改数据
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int UpdateManagerInfoDetail(ManagerInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MName = model.MName;
            string MPwd = model.MPwd;
            string MType = model.MType;
            string MId = model.MId.ToString();

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MName",MName),
                    new SQLiteParameter("@MPwd",MD5Encryption.GetEncryptionCharacter( MPwd)),
                    new SQLiteParameter("@MType",MType),
                    new SQLiteParameter("@MId",MId)
                };

            string sql = "UPDATE ManagerInfo SET MName = @MName,MPwd = @MPwd,MType = @MType WHERE MId = @MId";

            try
            {
                return SQLiteHelper.ExecuteNonQuery(sql, parms);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    errMessage = objException.InnerException.Message;
                    throw new Exception(objException.InnerException.Message);
                }
                errMessage = objException.Message;
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, parms, errMessage);
            }
        }
        /// <summary>
        ///  检查是否存在相同的用户名
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public List<byte[]> CheckHaveSameUserName(ManagerInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MName = model.MName;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MName",MName)
                };

            string sql = "SELECT 1 FROM ManagerInfo WHERE MName = @MName";
            try
            {
                string resultStr = Convert.ToString(SQLiteHelper.ExecuteScalar(sql, parms));

                // 接受数据的数据模型类的集合
                List<ManagerInfoModel_CheckHaveSameUserName> listCheckHaveSameUserNameModel = new List<ManagerInfoModel_CheckHaveSameUserName>();
                listCheckHaveSameUserNameModel.Add(new ManagerInfoModel_CheckHaveSameUserName()
                {
                    CharacterResult = resultStr
                });
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<ManagerInfoModel_CheckHaveSameUserName>(listCheckHaveSameUserNameModel);

                return listSerializeBuff;
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    errMessage = objException.InnerException.Message;
                    throw new Exception(objException.InnerException.Message);
                }
                errMessage = objException.Message;
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, parms, errMessage);
            }
        }
        /// <summary>
        ///  获取用户名的密码
        /// </summary>
        /// <returns></returns>
        public List<byte[]> GetUserPassWord(ManagerInfoModel model) 
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MName = model.MName;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MName",MName)
                };

            string sql = "SELECT MPwd,MType FROM ManagerInfo WHERE MName = @MName";
            try
            {
                DataTable dtTemp = SQLiteHelper.GetDataTable(sql, parms);
                // 接受数据的数据模型类的集合
                List<ManagerInfoModel_GetUserPassWord> listGetUserPassWordModel = new List<ManagerInfoModel_GetUserPassWord>();
                for (int i = 0; i < dtTemp.Rows.Count; i++)
                {
                    listGetUserPassWordModel.Add(new ManagerInfoModel_GetUserPassWord()
                    {
                        MPwd = ConvertWP.ToTrimString(dtTemp.Rows[i]["MPwd"]),
                        MType = Convert.ToString(dtTemp.Rows[i]["MType"])
                    });
                }
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<ManagerInfoModel_GetUserPassWord>(listGetUserPassWordModel);

                return listSerializeBuff;
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    errMessage = objException.InnerException.Message;
                    throw new Exception(objException.InnerException.Message);
                }
                errMessage = objException.Message;
                throw new Exception(objException.Message);
            }
            finally
            {
                sw.Stop();
                // 写日志
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql, parms, errMessage);
            }

        }
    }
}
