--- /usr/src/sys/netinet/ip_fw.h	Fri Jul 11 07:02:08 2003
+++ /usr/local/freebsdbrasil/cvs_root/usr/src/sys/netinet/ip_fw.h	Mon Jul 14 16:56:43 2003
@@ -261,11 +261,11 @@
  */
 typedef struct  _ipfw_insn_log {
         ipfw_insn o;
 	u_int32_t max_log;	/* how many do we log -- 0 = all */
 	u_int32_t log_left;	/* how many left to log 	*/
+	u_int32_t extended;	/* Extended logging */
 } ipfw_insn_log;
 
 /*
  * Here we have the structure representing an ipfw rule.
  *
