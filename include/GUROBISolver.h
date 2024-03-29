// This file is part of copra.

// copra is free software: you can redistribute it and/or
// modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// copra is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with copra.  If not, see
// <http://www.gnu.org/licenses/>.

#pragma once

#include "api.h"

#include "SolverInterface.h"
#include <Eigen/Core>
#include <eigen-gurobi/Gurobi.h>

namespace copra {

/**
 * GUROBISolver solver for both dense matrix.
 */
class COPRA_DLLAPI GUROBISolver : public SolverInterface // TODO: Enable sparse matrix
{
public:
    /**
     * GUROBISolver default constructor
     */
    GUROBISolver();

    int SI_fail() const override;
    void SI_inform() const override;
    int SI_iter() const override;
    void SI_printLevel(int pl) override;
    void SI_feasibilityTolerance(double tol) override;
    int SI_maxIter() const override;
    void SI_maxIter(int maxIter) override;

    bool SI_warmStart() const override;
    void SI_warmStart(bool w) override;

    /**
     * Get the solver's solution.
     * \return The qp solver result.
     */
    const Eigen::VectorXd& SI_result() const override;

    /**
     * Initialize the variables of the problem to solve.
     * \see SolverInterface::SI_problem()
     * \return The qp solver result.
     */
    void SI_problem(int nrVar, int nrEq, int nrInEq) override;

    /**
     * Solve the problem.
     * \see SolverInterface::SI_solve()
     * \return The qp solver result.
     */
    bool SI_solve(const Eigen::MatrixXd& Q, const Eigen::VectorXd& c,
        const Eigen::MatrixXd& Aeq, const Eigen::VectorXd& beq,
        const Eigen::MatrixXd& Aineq, const Eigen::VectorXd& bineq,
        const Eigen::VectorXd& XL, const Eigen::VectorXd& XU) override;

    Eigen::GurobiDense& baseSolver() noexcept { return solver_; }

    GUROBISolver* clone() const override { return new GUROBISolver(*this); }

private:
    Eigen::GurobiDense solver_;
};

} // namespace pc