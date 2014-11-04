#include <node.h>
#include "nan.h"
#include "lp_lib.h"

using namespace v8;

NAN_METHOD(getVersion);
NAN_METHOD(createLP);

NAN_METHOD(make_lp);
NAN_METHOD(read_XLI);
NAN_METHOD(read_MPS);
NAN_METHOD(read_mps);
NAN_METHOD(read_freeMPS);
NAN_METHOD(read_freemps);
NAN_METHOD(read_lp);
NAN_METHOD(read_LP);
// NAN_METHOD(free_lp);
// NAN_METHOD(read_lpex);
// NAN_METHOD(read_mpsex);
// NAN_METHOD(read_freempsex);

Persistent<Function> constructor;

class LinearProgram : public node::ObjectWrap {

public:

	static void Init(Handle<Object> exports);

private:
 	LinearProgram();
 	~LinearProgram();

static NAN_METHOD(New);
static NAN_METHOD(solve_async);

static NAN_METHOD(resize_lp);
static NAN_METHOD(get_status);
static NAN_METHOD(get_statustext);
static NAN_METHOD(is_obj_in_basis);
static NAN_METHOD(set_obj_in_basis);
static NAN_METHOD(copy_lp);
static NAN_METHOD(dualize_lp);
static NAN_METHOD(delete_lp);
static NAN_METHOD(set_lp_name);
static NAN_METHOD(get_lp_name);
static NAN_METHOD(has_BFP);
static NAN_METHOD(is_nativeBFP);
static NAN_METHOD(set_BFP);
static NAN_METHOD(write_XLI);
static NAN_METHOD(has_XLI);
static NAN_METHOD(is_nativeXLI);
static NAN_METHOD(set_XLI);
static NAN_METHOD(set_obj);
static NAN_METHOD(set_obj_fn);
static NAN_METHOD(set_obj_fnex);
static NAN_METHOD(str_set_obj_fn);
static NAN_METHOD(set_sense);
static NAN_METHOD(set_maxim);
static NAN_METHOD(set_minim);
static NAN_METHOD(is_maxim);
static NAN_METHOD(add_constraint);
static NAN_METHOD(add_constraintex);
static NAN_METHOD(set_add_rowmode);
static NAN_METHOD(is_add_rowmode);
static NAN_METHOD(str_add_constraint);
static NAN_METHOD(set_row);
static NAN_METHOD(set_rowex);
static NAN_METHOD(get_row);
static NAN_METHOD(get_rowex);
static NAN_METHOD(del_constraint);
static NAN_METHOD(add_lag_con);
static NAN_METHOD(str_add_lag_con);
static NAN_METHOD(set_lag_trace);
static NAN_METHOD(is_lag_trace);
static NAN_METHOD(set_constr_type);
static NAN_METHOD(get_constr_type);
static NAN_METHOD(get_constr_value);
static NAN_METHOD(is_constr_type);
static NAN_METHOD(set_rh);
static NAN_METHOD(get_rh);
static NAN_METHOD(set_rh_range);
static NAN_METHOD(get_rh_range);
static NAN_METHOD(set_rh_vec);
static NAN_METHOD(str_set_rh_vec);
static NAN_METHOD(add_column);
static NAN_METHOD(add_columnex);
static NAN_METHOD(str_add_column);
static NAN_METHOD(set_column);
static NAN_METHOD(set_columnex);
static NAN_METHOD(column_in_lp);
static NAN_METHOD(get_columnex);
static NAN_METHOD(get_column);
static NAN_METHOD(del_column);
static NAN_METHOD(set_mat);
static NAN_METHOD(get_mat);
static NAN_METHOD(get_mat_byindex);
static NAN_METHOD(get_nonzeros);
static NAN_METHOD(set_bounds_tighter);
static NAN_METHOD(get_bounds_tighter);
static NAN_METHOD(set_upbo);
static NAN_METHOD(get_upbo);
static NAN_METHOD(set_lowbo);
static NAN_METHOD(get_lowbo);
static NAN_METHOD(set_bounds);
static NAN_METHOD(set_unbounded);
static NAN_METHOD(is_unbounded);
static NAN_METHOD(set_int);
static NAN_METHOD(is_int);
static NAN_METHOD(set_binary);
static NAN_METHOD(is_binary);
static NAN_METHOD(set_semicont);
static NAN_METHOD(is_semicont);
static NAN_METHOD(is_negative);
static NAN_METHOD(set_var_weights);
static NAN_METHOD(get_var_priority);
static NAN_METHOD(set_pseudocosts);
static NAN_METHOD(get_pseudocosts);
static NAN_METHOD(add_SOS);
static NAN_METHOD(is_SOS_var);
static NAN_METHOD(set_row_name);
static NAN_METHOD(get_row_name);
static NAN_METHOD(get_origrow_name);
static NAN_METHOD(set_col_name);
static NAN_METHOD(get_col_name);
static NAN_METHOD(get_origcol_name);
static NAN_METHOD(unscale);
static NAN_METHOD(set_preferdual);
static NAN_METHOD(set_simplextype);
static NAN_METHOD(get_simplextype);
static NAN_METHOD(default_basis);
static NAN_METHOD(set_basiscrash);
static NAN_METHOD(get_basiscrash);
static NAN_METHOD(set_basisvar);
static NAN_METHOD(set_basis);
static NAN_METHOD(get_basis);
static NAN_METHOD(reset_basis);
static NAN_METHOD(guess_basis);
static NAN_METHOD(is_feasible);
static NAN_METHOD(solve);
static NAN_METHOD(time_elapsed);
// static NAN_METHOD(put_bb_nodefunc);
// static NAN_METHOD(put_bb_branchfunc);
// static NAN_METHOD(put_abortfunc);
// static NAN_METHOD(put_logfunc);
// static NAN_METHOD(put_msgfunc);
static NAN_METHOD(get_primal_solution);
// static NAN_METHOD(get_ptr_primal_solution);
static NAN_METHOD(get_dual_solution);
// static NAN_METHOD(get_ptr_dual_solution);
static NAN_METHOD(get_lambda);
// static NAN_METHOD(get_ptr_lambda);
static NAN_METHOD(write_mps);
static NAN_METHOD(write_MPS);
static NAN_METHOD(write_freemps);
static NAN_METHOD(write_freeMPS);
static NAN_METHOD(write_lp);
static NAN_METHOD(write_LP);
static NAN_METHOD(write_basis);
static NAN_METHOD(read_basis);
static NAN_METHOD(write_params);
static NAN_METHOD(read_params);
static NAN_METHOD(reset_params);
static NAN_METHOD(print_lp);
static NAN_METHOD(print_tableau);
static NAN_METHOD(print_objective);
static NAN_METHOD(print_solution);
static NAN_METHOD(print_constraints);
static NAN_METHOD(print_duals);
static NAN_METHOD(print_scales);
static NAN_METHOD(print_str);
static NAN_METHOD(set_outputstream);
static NAN_METHOD(set_outputfile);
static NAN_METHOD(set_verbose);
static NAN_METHOD(get_verbose);
// static NAN_METHOD(set_timeout);
static NAN_METHOD(get_timeout);
static NAN_METHOD(set_print_sol);
static NAN_METHOD(get_print_sol);
static NAN_METHOD(set_debug);
static NAN_METHOD(is_debug);
static NAN_METHOD(set_trace);
static NAN_METHOD(is_trace);
static NAN_METHOD(print_debugdump);
static NAN_METHOD(set_anti_degen);
static NAN_METHOD(get_anti_degen);
static NAN_METHOD(is_anti_degen);
static NAN_METHOD(set_presolve);
static NAN_METHOD(get_presolve);
static NAN_METHOD(get_presolveloops);
static NAN_METHOD(is_presolve);
static NAN_METHOD(get_orig_index);
static NAN_METHOD(get_lp_index);
static NAN_METHOD(set_maxpivot);
static NAN_METHOD(get_maxpivot);
static NAN_METHOD(set_obj_bound);
static NAN_METHOD(get_obj_bound);
static NAN_METHOD(set_mip_gap);
static NAN_METHOD(get_mip_gap);
static NAN_METHOD(set_bb_rule);
static NAN_METHOD(get_bb_rule);
static NAN_METHOD(set_var_branch);
static NAN_METHOD(get_var_branch);
static NAN_METHOD(is_infinite);
static NAN_METHOD(set_infinite);
static NAN_METHOD(get_infinite);
static NAN_METHOD(set_epsint);
static NAN_METHOD(get_epsint);
static NAN_METHOD(set_epsb);
static NAN_METHOD(get_epsb);
static NAN_METHOD(set_epsd);
static NAN_METHOD(get_epsd);
static NAN_METHOD(set_epsel);
static NAN_METHOD(get_epsel);
static NAN_METHOD(set_epslevel);
static NAN_METHOD(set_scaling);
static NAN_METHOD(get_scaling);
static NAN_METHOD(is_scalemode);
static NAN_METHOD(is_scaletype);
static NAN_METHOD(is_integerscaling);
static NAN_METHOD(set_scalelimit);
static NAN_METHOD(get_scalelimit);
static NAN_METHOD(set_improve);
static NAN_METHOD(get_improve);
static NAN_METHOD(set_pivoting);
static NAN_METHOD(get_pivoting);
static NAN_METHOD(set_partialprice);
static NAN_METHOD(get_partialprice);
static NAN_METHOD(set_multiprice);
static NAN_METHOD(get_multiprice);
static NAN_METHOD(is_use_names);
static NAN_METHOD(set_use_names);
static NAN_METHOD(get_nameindex);
static NAN_METHOD(is_piv_mode);
static NAN_METHOD(is_piv_rule);
static NAN_METHOD(set_break_at_first);
static NAN_METHOD(is_break_at_first);
static NAN_METHOD(set_bb_floorfirst);
static NAN_METHOD(get_bb_floorfirst);
static NAN_METHOD(set_bb_depthlimit);
static NAN_METHOD(get_bb_depthlimit);
static NAN_METHOD(set_break_at_value);
static NAN_METHOD(get_break_at_value);
static NAN_METHOD(set_negrange);
static NAN_METHOD(get_negrange);
static NAN_METHOD(set_epsperturb);
static NAN_METHOD(get_epsperturb);
static NAN_METHOD(set_epspivot);
static NAN_METHOD(get_epspivot);
static NAN_METHOD(get_max_level);
static NAN_METHOD(get_total_nodes);
static NAN_METHOD(get_total_iter);
static NAN_METHOD(get_objective);
static NAN_METHOD(get_working_objective);
static NAN_METHOD(get_var_primalresult);
static NAN_METHOD(get_var_dualresult);
static NAN_METHOD(get_variables);
// static NAN_METHOD(get_ptr_variables);
static NAN_METHOD(get_constraints);
// static NAN_METHOD(get_ptr_constraints);
static NAN_METHOD(get_sensitivity_rhs);
// static NAN_METHOD(get_ptr_sensitivity_rhs);
static NAN_METHOD(get_sensitivity_obj);
static NAN_METHOD(get_sensitivity_objex);
// static NAN_METHOD(get_ptr_sensitivity_obj);
// static NAN_METHOD(get_ptr_sensitivity_objex);
static NAN_METHOD(set_solutionlimit);
static NAN_METHOD(get_solutionlimit);
static NAN_METHOD(get_solutioncount);
static NAN_METHOD(get_Norig_rows);
static NAN_METHOD(get_Nrows);
static NAN_METHOD(get_Lrows);
static NAN_METHOD(get_Norig_columns);
static NAN_METHOD(get_Ncolumns);
// static NAN_METHOD(write_lpex);
// static NAN_METHOD(MPS_writefileex);
public:
	lprec* lp;
};

 //
