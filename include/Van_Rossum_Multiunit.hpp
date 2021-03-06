/*! \file Van_Rossum_Multiunit.hpp
 *
 *  C++ implementation of a kernel-based algorithm for calculating
 *  multi-unit Van Rossum spike train distances. See Houghton and
 *  Kreuz, On the efficient calculation of van Rossum
 *  distances. Network: Computation in Neural Systems, 2012, 23,
 *  48-58.
 *
 *  Original implementation by Conor Houghton (2012). Later changes by
 *  Eugenio Piasini (2013, 2014).
 *
 */
#ifndef VAN_ROSSUM_H
#define VAN_ROSSUM_H

#include<vector>

using namespace std;


/*!
 * Square (all-to-all) distance matrix for a set of multi-unit spike
 * trains.
 *
 * 
 * \param[in] d_matrix The trains.size() x trains.size() matrix where
 * the results will be written.
 *
 * \param[in] trains The set of multi unit spike trains.
 *
 * \param[in] tau Time scale for the exponential kernel. There is a
 * limit to how small tau can be compared to the absolute value of the
 * spike times. An exception will be raised if this limit is exceeded;
 * its value is system-dependent, but as a rule of thumb tau and the
 * spike times should be within 4 orders of magnitude of each other.
 *
 * \param[in] c Cosine of the multi-unit mixing angle. c=0 corresponds
 * to labelled-line code, c=1 to summed-population code.
 */
void d_exp_markage(double **d_matrix,
		   vector<vector<vector<double> > > & trains,
		   double tau,
		   double c);


/*!
 * Rectangular (bipartite) distance matrix for a set of multi-unit
 * spike trains (observations).
 *
 * 
 * \param[in] d_matrix The trains1.size() x trains2.size() matrix
 * where the results will be written.
 *
 * \param[in] trains1,trains2 The sets of multi unit spike trains.
 *
 * \param[in] tau Time scale for the exponential kernel. There is a
 * limit to how small tau can be compared to the absolute value of the
 * spike times. An exception will be raised if this limit is exceeded;
 * its value is system-dependent, but as a rule of thumb tau and the
 * spike times should be within 4 orders of magnitude of each other.
 *
 * \param[in] c Cosine of the multi-unit mixing angle. c=0 corresponds
 * to labelled-line code, c=1 to summed-population code.
 */
void d_exp_markage_rect(double **d_matrix,
			vector<vector<vector<double> > > & trains1,
			vector<vector<vector<double> > > & trains2,
			double tau,
			double c);


/*Internal helper functions*/

double big_r_with_exp_markage(vector<double> & fs);
double big_r_with_exp_markage(vector<double> & train_a, vector<double> & f_a,vector<long double> & e_pos_a,vector<long double> & e_neg_a,vector<double> & train_b, vector<double> & f_b,vector<long double> & e_pos_b,vector<long double> & e_neg_b);
void expage(vector<long double> & e_pos, vector<long double> & e_neg,vector<double> & train,double tau);
void markage(vector<double> & f, vector<long double> & e_pos, vector<long double> & e_neg, vector<double> & train,double tau);

#endif
