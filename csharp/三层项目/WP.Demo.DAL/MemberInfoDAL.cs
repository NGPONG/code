using System;
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
    public class MemberInfoDAL
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

            StringBuilder sql = new StringBuilder();
            sql.AppendLine("SELECT a.Mid,a.MName,b.MTitle as MTypeName,a.MPhone,a.MMoney FROM MemberInfo a");
            sql.AppendLine("LEFT JOIN MemberTypeInfo b on a.MTypeId = b.mid AND b.MIsDelete != 1");
            sql.AppendLine("WHERE a.MIsDelete != 1");

            try
            {
                DataTable dtTemp = SQLiteHelper.GetDataTable(sql.ToString());
                // 接受数据的数据模型类的集合
                List<MemberInfoModel_GetData> listGetDataModel = new List<MemberInfoModel_GetData>();
                for (int i = 0; i < dtTemp.Rows.Count; i++)
                {
                    listGetDataModel.Add(new MemberInfoModel_GetData()
                    {
                        MId = Convert.ToInt32(dtTemp.Rows[i]["MId"]),
                        MName = Convert.ToString(dtTemp.Rows[i]["MName"]),
                        MTypeName = Convert.ToString(dtTemp.Rows[i]["MTypeName"]),
                        MPhone = Convert.ToString(dtTemp.Rows[i]["MPhone"]),
                        MMoney = Convert.ToDecimal(dtTemp.Rows[i]["MMoney"])
                    });
                }
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<MemberInfoModel_GetData>(listGetDataModel);

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
                RecordText.Write(sw.Elapsed.TotalSeconds, methodName, sql.ToString(), null, errMessage);
            }
        }
        /// <summary>
        ///  检查是否存在相同的电话
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public List<byte[]> CheckHaveSamePhone(MemberInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MPhone = model.MPhone;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MPhone",MPhone)
                };

            string sql = "SELECT 1 FROM MemberInfo WHERE MPhone = @MPhone AND MIsDelete = 0";
            try
            {
                string resultStr = Convert.ToString(SQLiteHelper.ExecuteScalar(sql, parms));

                // 接受数据的数据模型类的集合
                List<MemberInfoModel_CheckHaveSamePhone> listCheckHaveSameUserNameModel = new List<MemberInfoModel_CheckHaveSamePhone>();
                listCheckHaveSameUserNameModel.Add(new MemberInfoModel_CheckHaveSamePhone()
                {
                    CharacterResult = resultStr
                });
                List<byte[]> listSerializeBuff = SerializableObject.SerializeObject<MemberInfoModel_CheckHaveSamePhone>(listCheckHaveSameUserNameModel);

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
        ///  新增数据
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int AddMemberInfoDetail(MemberInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MName = model.MName;
            int MTypeId = model.MTypeId;
            string MPhone = model.MPhone;
            string MMoney = model.MMoney;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MName",MName),
                    new SQLiteParameter("@MTypeId",MTypeId),
                    new SQLiteParameter("@MPhone",MPhone),
                    new SQLiteParameter("@MMoney",MMoney)
                };

            string sql = "insert into MemberInfo(MTypeId,MName,MPhone,MMoney,MIsDelete) values(@MTypeId,@MName,@MPhone,@MMoney,0)";

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
        public int UpdateMemberInfoDetail(MemberInfoModel model)
        {
            // 开启计时
            Stopwatch sw = new Stopwatch();
            sw.Start();
            // 错误信息
            string errMessage = string.Empty;
            // 函数名称
            string methodName = System.Reflection.MethodBase.GetCurrentMethod().ReflectedType.FullName + "." + new System.Diagnostics.StackTrace().GetFrame(0).GetMethod().Name;

            string MName = model.MName;
            string MPhone = model.MPhone;
            string MMoney = model.MMoney;
            int MTypeId = model.MTypeId;
            int MId = model.MId;

            SQLiteParameter[] parms = new SQLiteParameter[]{
                    new SQLiteParameter("@MName",MName),
                    new SQLiteParameter("@MTypeId",MTypeId),
                    new SQLiteParameter("@MPhone",MPhone),
                    new SQLiteParameter("@MMoney",MMoney),
                    new SQLiteParameter("@MId",MId)
                };

            string sql = "UPDATE MemberInfo SET MName = @MName,MTypeId = @MTypeId,MPhone = @MPhone,MMoney = @MMoney WHERE MId = @MId";

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
        ///  删除数据
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int DeleteMemberInfoDetail(MemberInfoModel model)
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

            string sql = "UPDATE MemberInfo SET MIsDelete = 1 WHERE MId = @MId";
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
    }
}
