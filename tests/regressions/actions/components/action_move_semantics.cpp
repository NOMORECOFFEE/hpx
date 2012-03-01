//  Copyright (c) 2007-2012 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpx/hpx.hpp>
#include <hpx/include/components.hpp>
#include <hpx/include/serialization.hpp>
#include <hpx/runtime/components/test_component_registry.hpp>

#include <tests/regressions/actions/components/server/action_move_semantics.hpp>

HPX_REGISTER_COMPONENT_MODULE();

using hpx::test::server::action_move_semantics;

typedef hpx::components::simple_component<action_move_semantics>
    action_move_semantics_type;

///////////////////////////////////////////////////////////////////////////////
// We use a special component registry for this component as it has to be
// disabled by default. All tests requiring this component to be active will
// enable it explicitly.

HPX_REGISTER_COMPONENT_FACTORY(
    hpx::components::component_factory<action_move_semantics_type>,
    test_action_move_semantics);
HPX_DEF_UNIQUE_COMPONENT_NAME(
    hpx::components::component_factory<action_move_semantics_type>,
    test_action_move_semantics);
template struct hpx::components::component_factory<action_move_semantics_type>;
HPX_REGISTER_TEST_COMPONENT_REGISTRY(
    hpx::components::component_factory<action_move_semantics_type>,
    test_action_move_semantics);

///////////////////////////////////////////////////////////////////////////////
HPX_REGISTER_ACTION_EX(
    hpx::test::server::action_move_semantics::test_movable_action,
    action_move_semantics_test_movable_action);
HPX_REGISTER_ACTION_EX(
    hpx::test::server::action_move_semantics::test_non_movable_action,
    action_move_semantics_test_non_movable_action);
HPX_REGISTER_ACTION_EX(
    hpx::test::server::action_move_semantics::test_movable_direct_action,
    action_move_semantics_test_movable_direct_action);
HPX_REGISTER_ACTION_EX(
    hpx::test::server::action_move_semantics::test_non_movable_direct_action,
    action_move_semantics_test_non_movable_direct_action);

HPX_REGISTER_ACTION_EX(
    hpx::test::server::action_move_semantics::return_test_movable_action,
    action_move_semantics_return_test_movable_action);
HPX_REGISTER_ACTION_EX(
    hpx::test::server::action_move_semantics::return_test_non_movable_action,
    action_move_semantics_return_test_non_movable_action);
HPX_REGISTER_ACTION_EX(
    hpx::test::server::action_move_semantics::return_test_movable_direct_action,
    action_move_semantics_return_test_movable_direct_action);
HPX_REGISTER_ACTION_EX(
    hpx::test::server::action_move_semantics::return_test_non_movable_direct_action,
    action_move_semantics_return_test_non_movable_direct_action);

HPX_DEFINE_GET_COMPONENT_TYPE(action_move_semantics);
