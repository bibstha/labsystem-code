<?php
/*
    labsystem.m-o-p.de -
                    the web based eLearning tool for practical exercises
    Copyright (C) 2010  Marc-Oliver Pahl

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
* Defines the constants for the user roles.
* These constants are essential for the user rights.
*
* If you change the constants here you have to change tham
* everywhere where they are used:
*    - elements visibility rights
*    - user rights
*    - config file default values
*    - menu
*
* Adding further user roles does not cause troubles where the
* numeric constant is not defined as the query returns false then.
* Duplicate differen meanings (e.g. 1024 = A in system alpha and
* 1024 = B in system beta will cause trouble as the system works
* only on the numerical constants!
*/

/* All values in here are shown as setable properties on the user rights page.
 * If you want to have less values use another roles file.
 * see user_roles and user_roles_useradmin for an example.
 * Restrictions:
 * -------------------------------------
 *    1 | someone who authenticated
 *    2 | is able to set the userrights
 *    4 | is able to edit pages
 *    8 | user will be available as mail supporter from the email-menu
 *   16 | user will be able to send to all IS_MAIL_RECEIVER and not only to IS_MAIL_SUPPORTER
 *   32 | user is available as mail receiver from within the system
 *   64 | is able to make schedules
 *  128 | is able to correct the closed labs
 *  256 | is able to view the example solutions
 */

/*
*  ***********************************************************************
*  * IMPORTANT: .INI FILES:                                              *
*  *   If you use this in the ini file you can not use the constants but *
*  *                   HAVE TO USE THE NUMERICAL VALUES!                 *
*  *   (The reason is, that constants in "" sections are not replaced).  *
*  ***********************************************************************

A user can have different roles: (each represented by a bit [ 2 ^= 0x0010, 4 ^= 0x0100, 8 ^= 0x1000], ...)
  - guest               */ define ( "IS_GUEST", "0" );
/*    everyone who enters the page and does not authenticate

  - user                */ define ( "IS_USER", "1" );
/*    someone who authenticated

  - user_rights_editor  */ define ( "IS_USER_RIGHTS_EDITOR", "2" );
/*    is able to set the userrights

  - contents editor     */ define ( "IS_CONTENT_EDITOR", "4" );
/*    is able to edit pages

  - mail_supporter      */ define ( "IS_MAIL_SUPPORTER", "8" );
/*    user will be available as mail supporter from the email-menu

  - roundmail_sender    */ define ( "IS_ALL_MAILER", "16" );
/*    user will be able to send to all IS_MAIL_RECEIVER and not only to IS_MAIL_SUPPORTER

  - roundmail_receiver  */ define ( "IS_MAIL_RECEIVER", "32" );
/*    user will be available to send mails from the site to

  - scheduler           */ define ( "IS_SCHEDULER", "64" );
/*    is able to make schedules

  - corrector           */ define ( "IS_CORRECTOR", "128" );
/*    is able to correct the closed labs

  - example_solution_viewer */ define ( "IS_EX_SOLUTION_VIEWER", "256" );
/*    is able to view the example solutions

-------------- above lab base system -------------------------------------

  For administrative tasks you have to provide:
                        */ define ( "MAX_USER_ROLE", IS_EX_SOLUTION_VIEWER );
/*                         Is used on iterations (p.e. 0..MAX_USER_ROLE).

  Since these are bit-values you can use the bit operators:
      IS_USER_RIGHTS_EDITOR | IS_PAGE_EDITOR
   ^= IS_USER_RIGHTS_EDITOR + IS_PAGE_EDITOR

  Is a value set? (p.e. IS_USER)
    (to_check & IS_USER == IS_USER)
 */
?>