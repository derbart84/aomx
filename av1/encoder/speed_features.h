/*
 * Copyright (c) 2016, Alliance for Open Media. All rights reserved
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at www.aomedia.org/license/software. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
 */

#ifndef AOM_AV1_ENCODER_SPEED_FEATURES_H_
#define AOM_AV1_ENCODER_SPEED_FEATURES_H_

#include "av1/common/enums.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
  INTRA_ALL = (1 << DC_PRED) | (1 << V_PRED) | (1 << H_PRED) | (1 << D45_PRED) |
              (1 << D135_PRED) | (1 << D113_PRED) | (1 << D157_PRED) |
              (1 << D203_PRED) | (1 << D67_PRED) | (1 << SMOOTH_PRED) |
              (1 << SMOOTH_V_PRED) | (1 << SMOOTH_H_PRED) | (1 << PAETH_PRED),
  UV_INTRA_ALL =
      (1 << UV_DC_PRED) | (1 << UV_V_PRED) | (1 << UV_H_PRED) |
      (1 << UV_D45_PRED) | (1 << UV_D135_PRED) | (1 << UV_D113_PRED) |
      (1 << UV_D157_PRED) | (1 << UV_D203_PRED) | (1 << UV_D67_PRED) |
      (1 << UV_SMOOTH_PRED) | (1 << UV_SMOOTH_V_PRED) |
      (1 << UV_SMOOTH_H_PRED) | (1 << UV_PAETH_PRED) | (1 << UV_CFL_PRED),
  UV_INTRA_DC = (1 << UV_DC_PRED),
  UV_INTRA_DC_CFL = (1 << UV_DC_PRED) | (1 << UV_CFL_PRED),
  UV_INTRA_DC_TM = (1 << UV_DC_PRED) | (1 << UV_PAETH_PRED),
  UV_INTRA_DC_PAETH_CFL =
      (1 << UV_DC_PRED) | (1 << UV_PAETH_PRED) | (1 << UV_CFL_PRED),
  UV_INTRA_DC_H_V = (1 << UV_DC_PRED) | (1 << UV_V_PRED) | (1 << UV_H_PRED),
  UV_INTRA_DC_H_V_CFL = (1 << UV_DC_PRED) | (1 << UV_V_PRED) |
                        (1 << UV_H_PRED) | (1 << UV_CFL_PRED),
  UV_INTRA_DC_PAETH_H_V = (1 << UV_DC_PRED) | (1 << UV_PAETH_PRED) |
                          (1 << UV_V_PRED) | (1 << UV_H_PRED),
  UV_INTRA_DC_PAETH_H_V_CFL = (1 << UV_DC_PRED) | (1 << UV_PAETH_PRED) |
                              (1 << UV_V_PRED) | (1 << UV_H_PRED) |
                              (1 << UV_CFL_PRED),
  INTRA_DC = (1 << DC_PRED),
  INTRA_DC_TM = (1 << DC_PRED) | (1 << PAETH_PRED),
  INTRA_DC_H_V = (1 << DC_PRED) | (1 << V_PRED) | (1 << H_PRED),
  INTRA_DC_PAETH_H_V =
      (1 << DC_PRED) | (1 << PAETH_PRED) | (1 << V_PRED) | (1 << H_PRED)
};

enum {
  INTER_ALL = (1 << NEARESTMV) | (1 << NEARMV) | (1 << GLOBALMV) |
              (1 << NEWMV) | (1 << NEAREST_NEARESTMV) | (1 << NEAR_NEARMV) |
              (1 << NEW_NEWMV) | (1 << NEAREST_NEWMV) | (1 << NEAR_NEWMV) |
              (1 << NEW_NEARMV) | (1 << NEW_NEARESTMV) | (1 << GLOBAL_GLOBALMV),
  INTER_NEAREST_NEAR_ZERO = (1 << NEARESTMV) | (1 << NEARMV) | (1 << GLOBALMV) |
                            (1 << NEAREST_NEARESTMV) | (1 << GLOBAL_GLOBALMV) |
                            (1 << NEAREST_NEWMV) | (1 << NEW_NEARESTMV) |
                            (1 << NEW_NEARMV) | (1 << NEAR_NEWMV) |
                            (1 << NEAR_NEARMV),
};

enum {
  DISABLE_ALL_INTER_SPLIT = (1 << THR_COMP_GA) | (1 << THR_COMP_LA) |
                            (1 << THR_ALTR) | (1 << THR_GOLD) | (1 << THR_LAST),

  DISABLE_ALL_SPLIT = (1 << THR_INTRA) | DISABLE_ALL_INTER_SPLIT,

  DISABLE_COMPOUND_SPLIT = (1 << THR_COMP_GA) | (1 << THR_COMP_LA),

  LAST_AND_INTRA_SPLIT_ONLY = (1 << THR_COMP_GA) | (1 << THR_COMP_LA) |
                              (1 << THR_ALTR) | (1 << THR_GOLD)
};

enum {
  TXFM_CODING_SF = 1,
  INTER_PRED_SF = 2,
  INTRA_PRED_SF = 4,
  PARTITION_SF = 8,
  LOOP_FILTER_SF = 16,
  RD_SKIP_SF = 32,
  RESERVE_2_SF = 64,
  RESERVE_3_SF = 128,
} UENUM1BYTE(DEV_SPEED_FEATURES);

enum {
  DIAMOND = 0,
  NSTEP = 1,
  HEX = 2,
  BIGDIA = 3,
  SQUARE = 4,
  FAST_HEX = 5,
  FAST_DIAMOND = 6
} UENUM1BYTE(SEARCH_METHODS);

enum {
  // No recode.
  DISALLOW_RECODE = 0,
  // Allow recode for KF and exceeding maximum frame bandwidth.
  ALLOW_RECODE_KFMAXBW = 1,
  // Allow recode only for KF/ARF/GF frames.
  ALLOW_RECODE_KFARFGF = 2,
  // Allow recode for all frames based on bitrate constraints.
  ALLOW_RECODE = 3,
} UENUM1BYTE(RECODE_LOOP_TYPE);

enum {
  SUBPEL_TREE = 0,
  SUBPEL_TREE_PRUNED = 1,           // Prunes 1/2-pel searches
  SUBPEL_TREE_PRUNED_MORE = 2,      // Prunes 1/2-pel searches more aggressively
  SUBPEL_TREE_PRUNED_EVENMORE = 3,  // Prunes 1/2- and 1/4-pel searches
  // Other methods to come
} UENUM1BYTE(SUBPEL_SEARCH_METHODS);

enum {
  USE_FULL_RD = 0,
  USE_FAST_RD,
  USE_LARGESTALL,
} UENUM1BYTE(TX_SIZE_SEARCH_METHOD);

enum {
  // Try the full image with different values.
  LPF_PICK_FROM_FULL_IMAGE,
  // Try a small portion of the image with different values.
  LPF_PICK_FROM_SUBIMAGE,
  // Estimate the level based on quantizer and frame type
  LPF_PICK_FROM_Q,
  // Pick 0 to disable LPF if LPF was enabled last frame
  LPF_PICK_MINIMAL_LPF
} UENUM1BYTE(LPF_PICK_METHOD);

enum {
  // Terminate search early based on distortion so far compared to
  // qp step, distortion in the neighborhood of the frame, etc.
  FLAG_EARLY_TERMINATE = 1 << 0,

  // Skips comp inter modes if the best so far is an intra mode.
  FLAG_SKIP_COMP_BESTINTRA = 1 << 1,

  // Skips oblique intra modes if the best so far is an inter mode.
  FLAG_SKIP_INTRA_BESTINTER = 1 << 3,

  // Skips oblique intra modes  at angles 27, 63, 117, 153 if the best
  // intra so far is not one of the neighboring directions.
  FLAG_SKIP_INTRA_DIRMISMATCH = 1 << 4,

  // Skips intra modes other than DC_PRED if the source variance is small
  FLAG_SKIP_INTRA_LOWVAR = 1 << 5,
} UENUM1BYTE(MODE_SEARCH_SKIP_LOGIC);

enum {
  NO_PRUNE = 0,
  // eliminates one tx type in vertical and horizontal direction
  PRUNE_ONE = 1,
  // eliminates two tx types in each direction
  PRUNE_TWO = 2,
  // adaptively prunes the least perspective tx types out of all 16
  // (tuned to provide negligible quality loss)
  PRUNE_2D_ACCURATE = 3,
  // similar, but applies much more aggressive pruning to get better speed-up
  PRUNE_2D_FAST = 4,
} UENUM1BYTE(TX_TYPE_PRUNE_MODE);

typedef struct {
  TX_TYPE_PRUNE_MODE prune_mode;
  int fast_intra_tx_type_search;
  int fast_inter_tx_type_search;

  // Use a skip flag prediction model to detect blocks with skip = 1 early
  // and avoid doing full TX type search for such blocks.
  int use_skip_flag_prediction;

  // Threshold used by the ML based method to predict TX block split decisions.
  int ml_tx_split_thresh;

  // skip remaining transform type search when we found the rdcost of skip is
  // better than applying transform
  int skip_tx_search;
} TX_TYPE_SEARCH;

enum {
  // Search partitions using RD criterion
  SEARCH_PARTITION,

  // Always use a fixed size partition
  FIXED_PARTITION,

  REFERENCE_PARTITION,

  VAR_BASED_PARTITION
} UENUM1BYTE(PARTITION_SEARCH_TYPE);

enum {
  EIGHTH_PEL,
  QUARTER_PEL,
  HALF_PEL,
  FULL_PEL
} UENUM1BYTE(SUBPEL_FORCE_STOP);

enum {
  NOT_IN_USE,
  DIRECT_PRED,
  RELAXED_PRED,
  ADAPT_PRED
} UENUM1BYTE(MAX_PART_PRED_MODE);

typedef struct MV_SPEED_FEATURES {
  // Motion search method (Diamond, NSTEP, Hex, Big Diamond, Square, etc).
  SEARCH_METHODS search_method;

  // This parameter controls which step in the n-step process we start at.
  // It's changed adaptively based on circumstances.
  int reduce_first_step_size;

  // If this is set to 1, we limit the motion search range to 2 times the
  // largest motion vector found in the last frame.
  int auto_mv_step_size;

  // Subpel_search_method can only be subpel_tree which does a subpixel
  // logarithmic search that keeps stepping at 1/2 pixel units until
  // you stop getting a gain, and then goes on to 1/4 and repeats
  // the same process. Along the way it skips many diagonals.
  SUBPEL_SEARCH_METHODS subpel_search_method;

  // Maximum number of steps in logarithmic subpel search before giving up.
  int subpel_iters_per_step;

  // When to stop subpel search.
  SUBPEL_FORCE_STOP subpel_force_stop;
} MV_SPEED_FEATURES;

#define MAX_MESH_STEP 4

typedef struct MESH_PATTERN {
  int range;
  int interval;
} MESH_PATTERN;

enum {
  GM_FULL_SEARCH,
  GM_REDUCED_REF_SEARCH_SKIP_L2_L3,
  GM_REDUCED_REF_SEARCH_SKIP_L2_L3_ARF2,
  GM_DISABLE_SEARCH
} UENUM1BYTE(GM_SEARCH_TYPE);

enum {
  GM_ERRORADV_TR_0,
  GM_ERRORADV_TR_1,
  GM_ERRORADV_TR_2,
  GM_ERRORADV_TR_TYPES,
} UENUM1BYTE(GM_ERRORADV_TYPE);

enum {
  NO_TRELLIS_OPT,          // No trellis optimization
  FULL_TRELLIS_OPT,        // Trellis optimization in all stages
  FINAL_PASS_TRELLIS_OPT,  // Trellis optimization in only the final encode pass
  NO_ESTIMATE_YRD_TRELLIS_OPT  // Disable trellis in estimate_yrd_for_sb
} UENUM1BYTE(TRELLIS_OPT_TYPE);

enum {
  FULL_TXFM_RD,
  LOW_TXFM_RD,
} UENUM1BYTE(TXFM_RD_MODEL);

enum {
  DIST_WTD_COMP_ENABLED,
  DIST_WTD_COMP_SKIP_MV_SEARCH,
  DIST_WTD_COMP_DISABLED,
} UENUM1BYTE(DIST_WTD_COMP_FLAG);

typedef enum {
  FLAG_SKIP_EIGHTTAP = 1 << EIGHTTAP_REGULAR,
  FLAG_SKIP_EIGHTTAP_SMOOTH = 1 << EIGHTTAP_SMOOTH,
  FLAG_SKIP_EIGHTTAP_SHARP = 1 << MULTITAP_SHARP,
} INTERP_FILTER_MASK;

typedef struct SPEED_FEATURES {
  MV_SPEED_FEATURES mv;

  // Frame level coding parameter update
  int frame_parameter_update;

  RECODE_LOOP_TYPE recode_loop;

  // Trellis (dynamic programming) optimization of quantized values
  TRELLIS_OPT_TYPE optimize_coefficients;

  // Global motion warp error threshold
  GM_ERRORADV_TYPE gm_erroradv_type;

  // Always set to 0. If on it enables 0 cost background transmission
  // (except for the initial transmission of the segmentation). The feature is
  // disabled because the addition of very large block sizes make the
  // backgrounds very to cheap to encode, and the segmentation we have
  // adds overhead.
  int static_segmentation;

  // Limit the inter mode tested in the RD loop
  int reduce_inter_modes;

  // Do not compute the global motion parameters for a LAST2_FRAME or
  // LAST3_FRAME if the GOLDEN_FRAME is closer and it has a non identity
  // global model.
  int selective_ref_gm;

  // If 1 we iterate finding a best reference for 2 ref frames together - via
  // a log search that iterates 4 times (check around mv for last for best
  // error of combined predictor then check around mv for alt). If 0 we
  // we just use the best motion vector found for each frame by itself.
  BLOCK_SIZE comp_inter_joint_search_thresh;

  // This variable is used to cap the maximum number of times we skip testing a
  // mode to be evaluated. A high value means we will be faster.
  int adaptive_rd_thresh;

  // Determine which method we use to determine transform size. We can choose
  // between options like full rd, largest for prediction size, largest
  // for intra and model coefs for the rest.
  TX_SIZE_SEARCH_METHOD tx_size_search_method;

  // Init search depth for square and rectangular transform partitions.
  // Values:
  // 0 - search full tree, 1: search 1 level, 2: search the highest level only
  int inter_tx_size_search_init_depth_sqr;
  int inter_tx_size_search_init_depth_rect;
  int intra_tx_size_search_init_depth_sqr;
  int intra_tx_size_search_init_depth_rect;
  // If any dimension of a coding block size above 64, always search the
  // largest transform only, since the largest transform block size is 64x64.
  int tx_size_search_lgr_block;

  PARTITION_SEARCH_TYPE partition_search_type;

  TX_TYPE_SEARCH tx_type_search;

  // Skip split transform block partition when the collocated bigger block
  // is selected as all zero coefficients.
  int txb_split_cap;

  // Shortcut the transform block partition and type search when the target
  // rdcost is relatively lower.
  // Values are 0 (not used) , or 1 - 2 with progressively increasing
  // aggressiveness
  int adaptive_txb_search_level;

  // Prune level for tx_size_type search for inter based on rd model
  // 0: no pruning
  // 1-2: progressively increasing aggressiveness of pruning
  int model_based_prune_tx_search_level;

  // Model based breakout after interpolation filter search
  // 0: no breakout
  // 1: use model based rd breakout
  int model_based_post_interp_filter_breakout;

  // Used if partition_search_type = FIXED_SIZE_PARTITION
  BLOCK_SIZE always_this_block_size;

  // Drop less likely to be picked reference frames in the RD search.
  // Has five levels for now: 0, 1, 2, 3 and 4, where higher levels prune more
  // aggressively than lower ones. (0 means no pruning).
  int selective_ref_frame;

  // Prune extended partition types search
  // Can take values 0 - 2, 0 referring to no pruning, and 1 - 2 increasing
  // aggressiveness of pruning in order.
  int prune_ext_partition_types_search_level;

  // Use a ML model to prune horz and vert partitions
  int ml_prune_rect_partition;

  // Disable/Enable interintra motion mode based on stats collected during
  // first_partition_search_pass
  int use_first_partition_pass_interintra_stats;

  // Use a ML model to prune horz_a, horz_b, vert_a and vert_b partitions.
  int ml_prune_ab_partition;

  // Use a ML model to prune horz4 and vert4 partitions.
  int ml_prune_4_partition;

  // Use a ML model to adaptively terminate partition search after trying
  // PARTITION_SPLIT. Can take values 0 - 2, 0 meaning not being enabled, and
  // 1 - 2 increasing aggressiveness in order.
  int ml_early_term_after_part_split_level;

  int fast_cdef_search;

  // 2-pass coding block partition search, and also use the mode decisions made
  // in the initial partition search to prune mode candidates, e.g. ref frames.
  int two_pass_partition_search;

  // Terminate early in firstpass of two_pass partition search for faster
  // firstpass.
  int firstpass_simple_motion_search_early_term;

  // Skip rectangular partition test when partition type none gives better
  // rd than partition type split. Can take values 0 - 2, 0 referring to no
  // skipping, and 1 - 2 increasing aggressiveness of skipping in order.
  int less_rectangular_check_level;

  // Use square partition only beyond this block size.
  BLOCK_SIZE use_square_partition_only_threshold;

  // Prune reference frames for rectangular partitions.
  // 0 implies no pruning
  // 1 implies prune for extended partition
  // 2 implies prune horiz, vert and extended partition
  int prune_ref_frame_for_rect_partitions;

  // Sets min and max square partition levels for this superblock based on
  // motion vector and prediction error distribution produced from 16x16
  // simple motion search
  MAX_PART_PRED_MODE auto_max_partition_based_on_simple_motion;
  int auto_min_partition_based_on_simple_motion;

  // Ensures the rd based auto partition search will always
  // go down at least to the specified level.
  BLOCK_SIZE rd_auto_partition_min_limit;

  // Min and max partition size we enable (block_size) as per auto
  // min max, but also used by adjust partitioning, and pick_partitioning.
  BLOCK_SIZE default_min_partition_size;
  BLOCK_SIZE default_max_partition_size;

  // Whether or not we allow partitions one smaller or one greater than the last
  // frame's partitioning. Only used if use_lastframe_partitioning is set.
  int adjust_partitioning_from_last_frame;

  // TODO(jingning): combine the related motion search speed features
  // This allows us to use motion search at other sizes as a starting
  // point for this motion search and limits the search range around it.
  int adaptive_motion_search;

  // Flag for allowing some use of exhaustive searches;
  int allow_exhaustive_searches;

  // Threshold for allowing exhaistive motion search.
  int exhaustive_searches_thresh;

  // Maximum number of exhaustive searches for a frame.
  int max_exaustive_pct;

  // Pattern to be used for any exhaustive mesh searches.
  MESH_PATTERN mesh_patterns[MAX_MESH_STEP];

  // Allows sub 8x8 modes to use the prediction filter that was determined
  // best for 8x8 mode. If set to 0 we always re check all the filters for
  // sizes less than 8x8, 1 means we check all filter modes if no 8x8 filter
  // was selected, and 2 means we use 8 tap if no 8x8 filter mode was selected.
  int adaptive_pred_interp_filter;

  // Adaptive prediction mode search
  int adaptive_mode_search;

  int alt_ref_search_fp;

  // Implements various heuristics to skip searching modes
  // The heuristics selected are based on  flags
  // defined in the MODE_SEARCH_SKIP_HEURISTICS enum
  unsigned int mode_search_skip_flags;

  // A source variance threshold below which filter search is disabled
  // Choose a very large value (UINT_MAX) to use 8-tap always
  unsigned int disable_filter_search_var_thresh;

  // Only enable wedge search if the edge strength is greater than
  // this threshold. A value of 0 signals that this check is disabled.
  unsigned int disable_wedge_search_edge_thresh;

  // Only enable wedge search if the variance is above this threshold.
  unsigned int disable_wedge_search_var_thresh;

  // Whether fast wedge sign estimate is used
  int fast_wedge_sign_estimate;

  // Whether to prune wedge search based on predictor difference
  int prune_wedge_pred_diff_based;

  // These bit masks allow you to enable or disable intra modes for each
  // transform size separately.
  int intra_y_mode_mask[TX_SIZES];
  int intra_uv_mode_mask[TX_SIZES];

  // This feature controls how the loop filter level is determined.
  LPF_PICK_METHOD lpf_pick;

  // This feature controls whether we do the expensive context update and
  // calculation in the rd coefficient costing loop.
  int use_fast_coef_costing;

  // This feature controls the tolerence vs target used in deciding whether to
  // recode a frame. It has no meaning if recode is disabled.
  int recode_tolerance;

  // This variable controls the maximum block size where intra blocks can be
  // used in inter frames.
  // TODO(aconverse): Fold this into one of the other many mode skips
  BLOCK_SIZE max_intra_bsize;

  // Partition search early breakout thresholds.
  int64_t partition_search_breakout_dist_thr;
  int partition_search_breakout_rate_thr;

  // Thresholds for ML based partition search breakout.
  int ml_partition_search_breakout_thresh[PARTITION_BLOCK_SIZES];

  // Allow skipping partition search for still image frame
  int allow_partition_search_skip;

  // Fast approximation of av1_model_rd_from_var_lapndz
  int simple_model_rd_from_var;

  // If true, sub-pixel search uses the exact convolve function used for final
  // encoding and decoding; otherwise, it uses bilinear interpolation.
  SUBPEL_SEARCH_TYPE use_accurate_subpel_search;

  // Whether to compute distortion in the image domain (slower but
  // more accurate), or in the transform domain (faster but less acurate).
  // 0: use image domain
  // 1: use transform domain in tx_type search, and use image domain for
  // RD_STATS
  // 2: use transform domain
  int use_transform_domain_distortion;

  GM_SEARCH_TYPE gm_search_type;

  // whether to disable the global motion recode loop
  int gm_disable_recode;

  // Do limited interpolation filter search for dual filters, since best choice
  // usually includes EIGHTTAP_REGULAR.
  int use_fast_interpolation_filter_search;

  // Disable dual filter
  int disable_dual_filter;

  // Save results of interpolation_filter_search for a block
  // Check mv and ref_frames before search, if they are same with previous
  // saved results, it can be skipped.
  int skip_repeat_interpolation_filter_search;

  // Use a hash table to store previously computed optimized qcoeffs from
  // expensive calls to optimize_txb.
  int use_hash_based_trellis;

  // flag to drop some ref frames in compound motion search
  int drop_ref;

  // flag to allow skipping intra mode for inter frame prediction
  int skip_intra_in_interframe;

  // Use hash table to store intra(keyframe only) txb transform search results
  // to avoid repeated search on the same residue signal.
  int use_intra_txb_hash;

  // Use hash table to store inter txb transform search results
  // to avoid repeated search on the same residue signal.
  int use_inter_txb_hash;

  // Use hash table to store macroblock RD search results
  // to avoid repeated search on the same residue signal.
  int use_mb_rd_hash;

  // Calculate RD cost before doing optimize_b, and skip if the cost is large.
  int optimize_b_precheck;

  // Use two-loop compound search
  int two_loop_comp_search;

  // Use model rd instead of transform search in second loop of compound search
  int second_loop_comp_fast_tx_search;

  // Decide when and how to use joint_comp.
  DIST_WTD_COMP_FLAG use_dist_wtd_comp_flag;

  // Decoder side speed feature to add penalty for use of dual-sgr filters.
  // Takes values 0 - 10, 0 indicating no penalty and each additional level
  // adding a penalty of 1%
  int dual_sgr_penalty_level;

  // 2-pass inter mode model estimation where the preliminary pass skips
  // transform search and uses a model to estimate rd, while the final pass
  // computes the full transform search. Two types of models are supported:
  // 0: not used
  // 1: used with online dynamic rd model
  // 2: used with static rd model
  int inter_mode_rd_model_estimation;

  // Skip some ref frames in compound motion search by single motion search
  // result. Has three levels for now: 0 referring to no skipping, and 1 - 3
  // increasing aggressiveness of skipping in order.
  // Note: The search order might affect the result. It is better to search same
  // single inter mode as a group.
  int prune_comp_search_by_single_result;

  // Skip certain motion modes (OBMC, warped, interintra) for single reference
  // motion search, using the results of single ref SIMPLE_TRANSLATION
  int prune_single_motion_modes_by_simple_trans;

  // Reuse the inter_intra_mode search result from NEARESTMV mode to other
  // single ref modes
  int reuse_inter_intra_mode;

  // Set the full pixel search level of obmc
  // 0: obmc_full_pixel_diamond
  // 1: obmc_refining_search_sad (faster)
  int obmc_full_pixel_search_level;

  // flag to skip NEWMV mode in drl if the motion search result is the same
  int skip_repeated_newmv;

  // Prune intra mode candidates based on source block gradient stats.
  int intra_angle_estimation;

  // Skip obmc or warped motion mode when neighborhood motion field is
  // identical
  int skip_obmc_in_uniform_mv_field;
  int skip_wm_in_uniform_mv_field;

  // Enable/disable ME for interinter wedge search.
  int disable_interinter_wedge_newmv_search;

  // Enable/disable smooth inter-intra mode
  int disable_smooth_interintra;

  // skip sharp_filter evaluation based on regular and smooth filter rd for
  // dual_filter=0 case
  int skip_sharp_interp_filter_search;

  // prune wedge and compound segment approximate rd evaluation based on
  // compound average rd/ref_best_rd
  int prune_comp_type_by_comp_avg;

  // Prune/gate motion mode evaluation based on token based rd
  // during transform search for inter blocks
  // Values are 0 (not used) , 1 - 3 with progressively increasing
  // aggressiveness
  int prune_motion_mode_level;

  // Gate warp evaluation for motions of type IDENTITY,
  // TRANSLATION and AFFINE(based on number of warp neighbors)
  int prune_warp_using_wmtype;

  // Perform simple_motion_search on each possible subblock and use it to prune
  // PARTITION_HORZ and PARTITION_VERT.
  int simple_motion_search_prune_rect;

  // Perform simple motion search before none_partition to decide if we
  // want to split directly without trying other partition types.
  int simple_motion_search_split_only;

  // Determines the type of model used by simple_motion_search_split_only. Only
  // valids when simple_motion_search_split_only is >= 1. Set to 1 for the
  // slower model that uses 5 subpixel searches, and 2 for the faster model that
  // uses 1 fullpixel search.
  int simple_motion_search_split_speed;

  // Use features from simple_motion_search to terminate prediction block
  // partition after PARTITION_NONE
  int simple_motion_search_early_term_none;

  int cb_pred_filter_search;

  // adaptive interp_filter search to allow skip of certain filter types.
  int adaptive_interp_filter_search;

  // mask for skip evaluation of certain interp_filter type.
  INTERP_FILTER_MASK interp_filter_search_mask;

  // Flag used to control the ref_best_rd based gating for chroma
  int perform_best_rd_based_gating_for_chroma;

  // Enable/disable interintra wedge search.
  int disable_wedge_interintra_search;

  // Disable loop restoration for Chroma plane
  int disable_loop_restoration_chroma;

  // Reduce the wiener filter win size for luma
  int reduce_wiener_window_size;

  // Flag used to control the extent of coeff R-D optimization
  int perform_coeff_opt;

  // Flag used to control the speed of the eob selection in trellis.
  int trellis_eob_fast;

  // This flag controls the use of non-RD mode decision.
  int use_nonrd_pick_mode;

  // prune wedge and compound segment approximate rd evaluation based on
  // compound average modeled rd
  int prune_comp_type_by_model_rd;

  // Enable/disable smooth intra modes.
  int disable_smooth_intra;

  // use reduced ref set for real-time mode
  int use_real_time_ref_set;

  // Perform a full TX search on some modes while using the
  // inter-mode RD model for others. Only enabled when
  // inter_mode_rd_model_estimation != 0
  int inter_mode_rd_model_estimation_adaptive;

  // Use very reduced set of inter mode checks and fast non-rd mode cost
  // estimation Only enabled when use_nonrd_pick_mode is != 0
  int use_fast_nonrd_pick_mode;

  // Reuse inter prediction in fast non-rd mode.
  int reuse_inter_pred_nonrd;

  // Perform croase ME before calculating variance in variance-based partition
  int estimate_motion_for_var_based_partition;
} SPEED_FEATURES;

struct AV1_COMP;

void av1_set_speed_features_framesize_independent(struct AV1_COMP *cpi,
                                                  int speed);
void av1_set_speed_features_framesize_dependent(struct AV1_COMP *cpi,
                                                int speed);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // AOM_AV1_ENCODER_SPEED_FEATURES_H_
