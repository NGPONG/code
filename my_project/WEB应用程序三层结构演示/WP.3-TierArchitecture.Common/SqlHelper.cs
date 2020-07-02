using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WP._3_TierArchitecture.Common
{
    public static class SqlHelper
    {
        /// <summary>
        ///  SQLite连接字符串
        /// </summary>
        public static string SqlConnectionCharacter = ConfigurationManager.ConnectionStrings["sqlConnectionStr"].ConnectionString;
        /// <summary>
        ///  执行非查询sql语句
        /// </summary>
        /// <param name="sql">sql语句</param>
        /// <param name="parms">参数</param>
        /// <returns>受影响的行数</returns>
        public static int ExecuteNonQuery(string sql, params SqlParameter[] parms)
        {
            try
            {
                int result = 0;
                using (SqlConnection connection = new SqlConnection(SqlHelper.SqlConnectionCharacter))
                {
                    connection.Open();

                    using (SqlCommand cmd = connection.CreateCommand())
                    {
                        cmd.CommandText = sql;
                        // 如果有参数
                        if (parms.Length > 0)
                        {
                            cmd.Parameters.AddRange(parms);
                        }
                        using (SqlTransaction tran = connection.BeginTransaction())
                        {
                            cmd.Transaction = tran;
                            try
                            {
                                result = cmd.ExecuteNonQuery();
                                tran.Commit();
                                return result;
                            }
                            catch (Exception objException)
                            {
                                tran.Rollback();
                                if (objException.InnerException != null)
                                {
                                    throw new Exception(objException.InnerException.Message);
                                }
                                throw new Exception(objException.Message);
                            }
                        }
                    }
                }
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  执行查询语句并返回一行一列的结果
        /// </summary>
        /// <param name="sql">sql语句</param>
        /// <param name="parms">参数</param>
        /// <returns>一行一列的结果</returns>
        public static object ExecuteScalar(string sql, params SqlParameter[] parms)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(SqlHelper.SqlConnectionCharacter))
                {
                    connection.Open();

                    using (SqlCommand cmd = connection.CreateCommand())
                    {
                        cmd.CommandText = sql;
                        // 如果有参数
                        if (parms.Length > 0)
                        {
                            cmd.Parameters.AddRange(parms);
                        }
                        return cmd.ExecuteScalar();
                    }
                }
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  获取SqlDataReader
        /// </summary>
        /// <param name="sql">sql语句</param>
        /// <param name="parms">参数</param>
        /// <returns>SQLiteDataReader</returns>
        public static SqlDataReader ExecuteReader(string sql, params SqlParameter[] parms)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(SqlHelper.SqlConnectionCharacter))
                {
                    connection.Open();

                    using (SqlCommand cmd = connection.CreateCommand())
                    {
                        cmd.CommandText = sql;
                        // 如果有参数
                        if (parms.Length > 0)
                        {
                            cmd.Parameters.AddRange(parms);
                        }

                        SqlDataReader reader = cmd.ExecuteReader();
                        return reader;
                    }
                }
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  获取查询结果集
        /// </summary>
        /// <param name="sql">sql语句</param>
        /// <param name="parms">参数</param>
        /// <returns>查询结果</returns>
        public static DataTable GetDataTable(string sql, params SqlParameter[] parms)
        {
            try
            {
                DataTable resultTable = new DataTable();

                using (SqlConnection connection = new SqlConnection(SqlHelper.SqlConnectionCharacter))
                {
                    connection.Open();

                    using (SqlCommand cmd = connection.CreateCommand())
                    {
                        cmd.CommandText = sql;
                        // 如果有参数
                        if (parms.Length > 0)
                        {
                            cmd.Parameters.AddRange(parms);
                        }
                        using (SqlDataAdapter adapter = new SqlDataAdapter(cmd))
                        {
                            adapter.Fill(resultTable);
                        }
                    }
                }
                return resultTable;
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
    }
}
