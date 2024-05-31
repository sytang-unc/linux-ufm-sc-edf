#undef TRACE_SYSTEM
#define TRACE_SYSTEM uscedf

#if !defined(_TRACE_USCEDF_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_USCEDF_H
#include <linux/tracepoint.h>

#include<linux/sched.h>

#define edf_timestamp ktime_get()

TRACE_EVENT(uscedf_missed_deadline, 
    
    TP_PROTO(struct task_struct *t, s64 miss),
    
    TP_ARGS(t, miss),
    
    TP_STRUCT__entry(
	    __field(	pid_t,	pid	)
		__field(	s64,	time	)
		__field(	s64,	miss	)
		__field(	u64,	period	)
	),
    
    TP_fast_assign(
		__entry->pid = t->pid;
		__entry->time = edf_timestamp;
		__entry->miss = miss;
		__entry->period = t->dl.dl_period;
	),

	TP_printk("MISSED_DEADLINE %lld %lld %llu %d", \
		__entry->time, __entry->miss, __entry->period, __entry->pid)
);

TRACE_EVENT(uscedf_find_later_rq_start,

	TP_PROTO(struct task_struct *t),

	TP_ARGS(t),

	TP_STRUCT__entry(
		__field(	pid_t,	pid	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->pid = t->pid;
		__entry->time = edf_timestamp;
	),

	TP_printk("FIND_LATER_RQ_START %lld %d", __entry->time, __entry->pid)
);

TRACE_EVENT(uscedf_find_later_rq_end,

	TP_PROTO(struct task_struct *t),

	TP_ARGS(t),

	TP_STRUCT__entry(
		__field(	pid_t,	pid	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->pid = t->pid;
		__entry->time = edf_timestamp;
	),

	TP_printk("FIND_LATER_RQ_END %lld %d", __entry->time, __entry->pid)
);

TRACE_EVENT(uscedf_enqueue_start,
    
    TP_PROTO(struct task_struct *t),
    
    TP_ARGS(t),

    TP_STRUCT__entry(
		__field(	pid_t,	pid	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->pid = t->pid;
		__entry->time = edf_timestamp;
	),

	TP_printk("ENQUEUE_START %lld %d", __entry->time, __entry->pid)
);

TRACE_EVENT(uscedf_enqueue_end,
    
    TP_PROTO(struct task_struct *t),
    
    TP_ARGS(t),

    TP_STRUCT__entry(
		__field(	pid_t,	pid	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->pid = t->pid;
		__entry->time = edf_timestamp;
	),

	TP_printk("ENQUEUE_END %lld %d", __entry->time, __entry->pid)
);

TRACE_EVENT(uscedf_dequeue_start,
    
    TP_PROTO(struct task_struct *t),
    
    TP_ARGS(t),

    TP_STRUCT__entry(
		__field(	pid_t,	pid	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->pid = t->pid;
		__entry->time = edf_timestamp;
	),

	TP_printk("DEQUEUE_START %lld %d", __entry->time, __entry->pid)
);

TRACE_EVENT(uscedf_dequeue_end,
    
    TP_PROTO(struct task_struct *t),
    
    TP_ARGS(t),

    TP_STRUCT__entry(
		__field(	pid_t,	pid	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->pid = t->pid;
		__entry->time = edf_timestamp;
	),

	TP_printk("DEQUEUE_END %lld %d", __entry->time, __entry->pid)
);

TRACE_EVENT(uscedf_migrated,

	TP_PROTO(struct task_struct *t, int dest_cpu),

	TP_ARGS(t, dest_cpu),

	TP_STRUCT__entry(
		__field(	pid_t,	pid		)
		__field(	int,	orig_cpu	)
		__field(	int,	dest_cpu	)
		__field(	s64,	time		)
	),

	TP_fast_assign(
		__entry->pid = t->pid;
		__entry->orig_cpu = task_cpu(t);
		__entry->dest_cpu = dest_cpu;
		__entry->time = edf_timestamp;
	),

	TP_printk("MIGRATED %lld %d %d %d", __entry->time, __entry->pid, __entry->orig_cpu, __entry->dest_cpu)
);

TRACE_EVENT(uscedf_wdl_check_start,

	TP_PROTO(struct rq *rq),
    
	TP_ARGS(rq),

	TP_STRUCT__entry(
		__field(	int,	cpu	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->cpu = rq->cpu;
		__entry->time = edf_timestamp;
	),

	TP_printk("WDL_CHECK_START %lld %d", __entry->time, __entry->cpu)
);

TRACE_EVENT(uscedf_wdl_check_end,

	TP_PROTO(struct rq *rq),
    
	TP_ARGS(rq),

	TP_STRUCT__entry(
		__field(	int,	cpu	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->cpu = rq->cpu;
		__entry->time = edf_timestamp;
	),

	TP_printk("WDL_CHECK_END %lld %d", __entry->time, __entry->cpu)
);

TRACE_EVENT(uscedf_wdl_preempt_start,

	TP_PROTO(struct rq *rq),
    
	TP_ARGS(rq),

	TP_STRUCT__entry(
		__field(	int,	cpu	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->cpu = rq->cpu;
		__entry->time = edf_timestamp;
	),

	TP_printk("WDL_PREEMPT_START %lld %d", __entry->time, __entry->cpu)
);

TRACE_EVENT(uscedf_wdl_preempt_end,

	TP_PROTO(struct rq *rq),
    
	TP_ARGS(rq),

	TP_STRUCT__entry(
		__field(	int,	cpu	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->cpu = rq->cpu;
		__entry->time = edf_timestamp;
	),

	TP_printk("WDL_PREEMPT_END %lld %d", __entry->time, __entry->cpu)
);

TRACE_EVENT(uscedf_swap_check_start,

	TP_PROTO(struct rq *rq),
    
	TP_ARGS(rq),

	TP_STRUCT__entry(
		__field(	int,	cpu	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->cpu = rq->cpu;
		__entry->time = edf_timestamp;
	),

	TP_printk("WDL_SWAP_CHECK_START %lld %d", __entry->time, __entry->cpu)
);

TRACE_EVENT(uscedf_swap_check_end,

	TP_PROTO(struct rq *rq),
    
	TP_ARGS(rq),

	TP_STRUCT__entry(
		__field(	int,	cpu	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->cpu = rq->cpu;
		__entry->time = edf_timestamp;
	),

	TP_printk("WDL_SWAP_CHECK_END %lld %d", __entry->time, __entry->cpu)
);

TRACE_EVENT(uscedf_swap_start,

	TP_PROTO(struct rq *rq),
    
	TP_ARGS(rq),

	TP_STRUCT__entry(
		__field(	int,	cpu	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->cpu = rq->cpu;
		__entry->time = edf_timestamp;
	),

	TP_printk("WDL_SWAP_START %lld %d", __entry->time, __entry->cpu)
);

TRACE_EVENT(uscedf_swap_end,

	TP_PROTO(struct rq *rq),
    
	TP_ARGS(rq),

	TP_STRUCT__entry(
		__field(	int,	cpu	)
		__field(	s64,	time	)
	),

	TP_fast_assign(
		__entry->cpu = rq->cpu;
		__entry->time = edf_timestamp;
	),

	TP_printk("WDL_SWAP_END %lld %d", __entry->time, __entry->cpu)
);

#endif /* _TRACE_USCEDF_H */

/* This part must be outside protection */
#include <trace/define_trace.h>