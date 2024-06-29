#undef TRACE_SYSTEM
#define TRACE_SYSTEM uscedf_debug

#if !defined(_TRACE_USCEDF_DEBUG_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_USCEDF_DEBUG_H
#include <linux/tracepoint.h>

#include<linux/sched.h>

TRACE_EVENT(uscedf_debug_wdl_compare,

	TP_PROTO(int cpu, u64 wdl, u64 orig_dl, u64 other_dl, u64 preempt_dl, u64 orig_preempt),
    
	TP_ARGS(cpu, wdl, orig_dl, other_dl, preempt_dl, orig_preempt),

	TP_STRUCT__entry(
		__field(	int,	cpu		)
		__field(	u64,	wdl		)
		__field(	u64,	orig_dl		)
		__field(	u64,	other_dl	)
		__field(	u64,	preempt_dl	)
		__field(	u64,	orig_preempt	)
		__field(	u64,	now		)
	),

	TP_fast_assign(
		__entry->cpu = cpu;
		__entry->wdl = wdl;
		__entry->orig_dl = orig_dl;
		__entry->other_dl = other_dl;
		__entry->preempt_dl = preempt_dl;
		__entry->orig_preempt = orig_preempt;
		__entry->now = ktime_get_ns();
	),

	TP_printk("DEBUG_WDL_COMPARE CPU:%d WDL:%llu ORIG:%llu OPP:%llu PREEMPT:%llu ORIG_PREEMPT: %llu NOW:%llu", 
		__entry->cpu, __entry->wdl, __entry->orig_dl, __entry->other_dl, __entry->preempt_dl, __entry->orig_preempt, __entry->now)
);

TRACE_EVENT(uscedf_debug_wdl_push,

	TP_PROTO(int cpu, struct task_struct *t),
	
	TP_ARGS(cpu, t),
	
	TP_STRUCT__entry(
		__field(	int,	cpu		)
		__field(	pid_t,	pid		)
	),
	
	TP_fast_assign(
		__entry->cpu = cpu;
		__entry->pid = t->pid;
	),

	TP_printk("DEBUG_WDL_PUSH CPU:%d PID:%d", __entry->cpu, __entry->pid)

);

TRACE_EVENT(uscedf_debug_bl_next_updated,

	TP_PROTO(struct root_domain *rd),

	TP_ARGS(rd),

	TP_STRUCT__entry(
		__field(	u64,	big_next	)
		__field(	u64,	little_next	)
	),

	TP_fast_assign(
		__entry->big_next = rd->big_next;
		__entry->little_next = rd->little_next;
	),

	TP_printk("DEBUG_BL_NEXT_UPDATED BIG_NEXT:%llu LITTLE_NEXT:%llu", __entry->big_next, __entry->little_next)
);

TRACE_EVENT(uscedf_debug_bl_deadline_updated,

	TP_PROTO(struct root_domain *rd),

	TP_ARGS(rd),

	TP_STRUCT__entry(
		__field(	u64,	big_dl		)
		__field(	u64,	little_dl	)
	),

	TP_fast_assign(
		__entry->big_dl = rd->big_deadline;
		__entry->little_dl = rd->little_deadline;
	),

	TP_printk("DEBUG_BL_NEXT_UPDATED BIG_DL:%llu LITTLE_DL:%llu", __entry->big_dl, __entry->little_dl)
);

TRACE_EVENT(uscedf_debug_rq_next_updated,

	TP_PROTO(struct rq *rq, int global),

	TP_ARGS(rq, global),

	TP_STRUCT__entry(
		__field(	int,	cpu		)
		__field(	u64,	next		)
		__field(	u64,	next_global	)
		__field(	int,	global_update	)
	),

	TP_fast_assign(
		__entry->cpu = rq->cpu;
		__entry->next = rq->dl.earliest_dl.next;
		__entry->next_global = rq->dl.earliest_dl.next_global;
		__entry->global_update = global;
	),

	TP_printk("DEBUG_RQ_NEXT_UPDATED CPU:%d NEXT:%llu GLOBAL:%llu WAS_GLOBAL_UPDATE:%d", __entry->cpu, __entry->next, __entry->next_global, __entry->global_update)
);

TRACE_EVENT(uscedf_debug_rq_enqueued,

	TP_PROTO(struct rq *rq, struct task_struct *t),

	TP_ARGS(rq, t),

	TP_STRUCT__entry(
		__field(	int,	cpu		)
		__field(	pid_t,	pid		)
		__field(	u64,	dl		)
	),

	TP_fast_assign(
		__entry->cpu = rq->cpu;
		__entry->pid = t->pid;
		__entry->dl = t->dl.deadline;
	),

	TP_printk("DEBUG_RQ_ENQUEUED CPU:%d PID:%d DL:%llu", __entry->cpu, __entry->pid, __entry->dl)
);

TRACE_EVENT(uscedf_debug_rq_dequeued,

	TP_PROTO(struct rq *rq, struct task_struct *t),

	TP_ARGS(rq, t),

	TP_STRUCT__entry(
		__field(	int,	cpu		)
		__field(	pid_t,	pid		)
		__field(	u64,	dl		)
	),

	TP_fast_assign(
		__entry->cpu = rq->cpu;
		__entry->pid = t->pid;
		__entry->dl = t->dl.deadline;
	),

	TP_printk("DEBUG_RQ_DEQUEUED CPU:%d PID:%d DL:%llu", __entry->cpu, __entry->pid, __entry->dl)
);

#endif /* _TRACE_USCEDF_DEBUG_H */

/* This part must be outside protection */
#include <trace/define_trace.h>