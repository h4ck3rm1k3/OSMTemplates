#pragma once

/*
  copyright 2009 
  "James Michael Dupont (H4ck3rm1k3)"  <jamesmikedupont@gmail.com>
  http://www.fsf.org/licensing/licenses/agpl-3.0.html

 This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

namespace OSM
{
// real attributes, part of the OSM schema
// constant strings 
static XMLCh szID[]={ chLatin_i, chLatin_d, chNull }; // ID
static XMLCh szK[]={ chLatin_k,  chNull }; // K (key)
static XMLCh szV[]={ chLatin_v,  chNull }; // V (key)
static XMLCh szLON[]={ chLatin_l, chLatin_o, chLatin_n, chNull }; // lon
static XMLCh szLAT[]={ chLatin_l, chLatin_a, chLatin_t, chNull }; // lat

static XMLCh szMEMBER[]={chLatin_m,chLatin_e,chLatin_m,chLatin_b,chLatin_e,chLatin_r, chNull }; // member
static XMLCh szBOUND[]={chLatin_b,chLatin_o,chLatin_u,chLatin_n,chLatin_d, chNull }; // bound
static XMLCh szOSM[]={chLatin_o,chLatin_s,chLatin_m, chNull }; // osm

// attribute names are matched differently...
static XMLCh szNAME[]={ chLatin_n, chLatin_a, chLatin_m, chLatin_e, chNull }; // name

static XMLCh szNAME1[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chDigit_1, chNull }; // name1
static XMLCh szNAME2[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chDigit_2, chNull }; // name2
static XMLCh szNAME_1[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chDigit_1, chNull }; // name_1
static XMLCh szNAME_2[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chDigit_2, chNull }; // name_2
static XMLCh szNAME_3[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chDigit_3, chNull }; // name_3
static XMLCh szNAME_4[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chDigit_4, chNull }; // name_4
static XMLCh szNAME_5[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chDigit_5, chNull }; // name_5
static XMLCh szNAME_ABBREVIATION[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_a,chLatin_b,chLatin_b,chLatin_r,chLatin_e,chLatin_v,chLatin_i,chLatin_a,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // name:abbreviation
static XMLCh szNAME_ALT[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_a,chLatin_l,chLatin_t, chNull }; // name:alt
static XMLCh szNAME_DE[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_d,chLatin_e, chNull }; // name:de
static XMLCh szNAME_EN[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_e,chLatin_n, chNull }; // name:en
static XMLCh szNAME_EO[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_e,chLatin_o, chNull }; // name:eo
static XMLCh szNAME_FR[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_f,chLatin_r, chNull }; // name:fr
static XMLCh szNAME_FUTURE[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_f,chLatin_u,chLatin_t,chLatin_u,chLatin_r,chLatin_e, chNull }; // name:future
static XMLCh szNAME_LV[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_l,chLatin_v, chNull }; // name:lv
static XMLCh szNAME_NL[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_n,chLatin_l, chNull }; // name:nl
static XMLCh szNAME_RU[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_r,chLatin_u, chNull }; // name:ru
static XMLCh szNAME_SHORT[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_s,chLatin_h,chLatin_o,chLatin_r,chLatin_t, chNull }; // name:short
static XMLCh szNAME_SK[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chColon,chLatin_s,chLatin_k, chNull }; // name:sk
static XMLCh szNAME_TYPE[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_t,chLatin_y,chLatin_p,chLatin_e, chNull }; // name_type
static XMLCh szNAME_[]={chLatin_n,chLatin_a,chLatin_m,chLatin_e,chSpace, chNull }; // name 



// types of elements
static XMLCh szWAY[]={chLatin_w,chLatin_a,chLatin_y, chNull }; // way
static XMLCh szRELATION[]={chLatin_r,chLatin_e,chLatin_l,chLatin_a,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // relation
static XMLCh szNODE[]={chLatin_n,chLatin_o,chLatin_d,chLatin_e, chNull }; // node
static XMLCh szND[]={chLatin_n,chLatin_d,chNull }; // nd
static XMLCh szTAG[]={chLatin_t,chLatin_a,chLatin_g, chNull }; // wag

static XMLCh szVISIBLE[]={chLatin_v,chLatin_i,chLatin_s,chLatin_i,chLatin_b,chLatin_l,chLatin_e, chNull }; // visible
static XMLCh szUSER[]={chLatin_u,chLatin_s,chLatin_e,chLatin_r, chNull }; // user

static XMLCh szTIMESTAMP[]={chLatin_t,chLatin_i,chLatin_m,chLatin_e,chLatin_s,chLatin_t,chLatin_a,chLatin_m,chLatin_p, chNull }; // timestamp

  // ref
static XMLCh szREF[]={chLatin_r,chLatin_e,chLatin_f, chNull }; // <way> list of <nd ref="node:id"/> </way>

// ELEV 
static XMLCh szELEV[]={chLatin_E,chLatin_L,chLatin_E, chLatin_V, chNull }; // elevation


  // public:
  // keys from the attribute tag where the names listed below are the kets key value  :


// values from the counties
///  FOR ROADS :

static XMLCh szABANDONED[]={chLatin_a,chLatin_b,chLatin_a,chLatin_n,chLatin_d,chLatin_o,chLatin_n,chLatin_e,chLatin_d, chNull }; // abandoned
static XMLCh szACCESS[]={chLatin_a,chLatin_c,chLatin_c,chLatin_e,chLatin_s,chLatin_s, chNull }; // access
static XMLCh szACC[]={chLatin_a,chLatin_c,chLatin_c, chNull }; // acc
static XMLCh szACREAGE[]={chLatin_a,chLatin_c,chLatin_r,chLatin_e,chLatin_a,chLatin_g,chLatin_e, chNull }; // acreage
static XMLCh szADDR_CITY[]={chLatin_a,chLatin_d,chLatin_d,chLatin_r,chColon,chLatin_c,chLatin_i,chLatin_t,chLatin_y, chNull }; // addr:city
static XMLCh szADDR_COUNTRY[]={chLatin_a,chLatin_d,chLatin_d,chLatin_r,chColon,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_r,chLatin_y, chNull }; // addr:country
static XMLCh szADDR_FULL[]={chLatin_a,chLatin_d,chLatin_d,chLatin_r,chColon,chLatin_f,chLatin_u,chLatin_l,chLatin_l, chNull }; // addr:full
static XMLCh szADDR_HOUSENUMBER[]={chLatin_a,chLatin_d,chLatin_d,chLatin_r,chColon,chLatin_h,chLatin_o,chLatin_u,chLatin_s,chLatin_e,chLatin_n,chLatin_u,chLatin_m,chLatin_b,chLatin_e,chLatin_r, chNull }; // addr:housenumber
static XMLCh szADDR_INTERPOLATION[]={chLatin_a,chLatin_d,chLatin_d,chLatin_r,chColon,chLatin_i,chLatin_n,chLatin_t,chLatin_e,chLatin_r,chLatin_p,chLatin_o,chLatin_l,chLatin_a,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // addr:interpolation
static XMLCh szADDR_POSTCODE[]={chLatin_a,chLatin_d,chLatin_d,chLatin_r,chColon,chLatin_p,chLatin_o,chLatin_s,chLatin_t,chLatin_c,chLatin_o,chLatin_d,chLatin_e, chNull }; // addr:postcode
static XMLCh szADDR_STATE[]={chLatin_a,chLatin_d,chLatin_d,chLatin_r,chColon,chLatin_s,chLatin_t,chLatin_a,chLatin_t,chLatin_e, chNull }; // addr:state
static XMLCh szADDR_STREET[]={chLatin_a,chLatin_d,chLatin_d,chLatin_r,chColon,chLatin_s,chLatin_t,chLatin_r,chLatin_e,chLatin_e,chLatin_t, chNull }; // addr:street


static XMLCh szAERIALWAY[]={chLatin_a,chLatin_e,chLatin_r,chLatin_i,chLatin_a,chLatin_l,chLatin_w,chLatin_a,chLatin_y, chNull }; // aerialway
static XMLCh szAEROWAY[]={chLatin_a,chLatin_e,chLatin_r,chLatin_o,chLatin_w,chLatin_a,chLatin_y, chNull }; // aeroway
static XMLCh szALT_NAME[]={chLatin_a,chLatin_l,chLatin_t,chUnderscore,chLatin_n,chLatin_a,chLatin_m,chLatin_e, chNull }; // alt_name
static XMLCh szAMENITY[]={chLatin_A,chLatin_m,chLatin_e,chLatin_n,chLatin_i,chLatin_t,chLatin_y, chNull }; // Amenity

static XMLCh szAME[]={chLatin_A,chLatin_m,chLatin_e, chNull }; // Ame
static XMLCh szAREA[]={chLatin_a,chLatin_r,chLatin_e,chLatin_a, chNull }; // area
static XMLCh szATM[]={chLatin_a,chLatin_t,chLatin_m, chNull }; // atm
static XMLCh szATTRACTION[]={chLatin_a,chLatin_t,chLatin_t,chLatin_r,chLatin_a,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // attraction
static XMLCh szBACKREST[]={chLatin_b,chLatin_a,chLatin_c,chLatin_k,chLatin_r,chLatin_e,chLatin_s,chLatin_t, chNull }; // backrest
static XMLCh szBARRIER[]={chLatin_b,chLatin_a,chLatin_r,chLatin_r,chLatin_i,chLatin_e,chLatin_r, chNull }; // barrier
static XMLCh szBEACH[]={chLatin_b,chLatin_e,chLatin_a,chLatin_c,chLatin_h, chNull }; // beach
static XMLCh szBICYCLE[]={chLatin_b,chLatin_i,chLatin_c,chLatin_y,chLatin_c,chLatin_l,chLatin_e, chNull }; // bicycle
static XMLCh szBOAT[]={chLatin_b,chLatin_o,chLatin_a,chLatin_t, chNull }; // boat


static XMLCh szBRIDGE[]={chLatin_b,chLatin_r,chLatin_i,chLatin_d,chLatin_g,chLatin_e, chNull }; // bridge
static XMLCh szBRIDLEWAY[]={chLatin_b,chLatin_r,chLatin_i,chLatin_d,chLatin_l,chLatin_e,chLatin_w,chLatin_a,chLatin_y, chNull }; // bridleway
static XMLCh szBUILDING[]={chLatin_b,chLatin_u,chLatin_i,chLatin_l,chLatin_d,chLatin_i,chLatin_n,chLatin_g, chNull }; // building
static XMLCh szBUILDING_CLADDING[]={chLatin_b,chLatin_u,chLatin_i,chLatin_l,chLatin_d,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_c,chLatin_l,chLatin_a,chLatin_d,chLatin_d,chLatin_i,chLatin_n,chLatin_g, chNull }; // building:cladding
static XMLCh szBUILDING_LEVELPLAN[]={chLatin_b,chLatin_u,chLatin_i,chLatin_l,chLatin_d,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_l,chLatin_e,chLatin_v,chLatin_e,chLatin_l,chLatin_P,chLatin_l,chLatin_a,chLatin_n, chNull }; // building:levelPlan
static XMLCh szBUILDING_LEVELS[]={chLatin_b,chLatin_u,chLatin_i,chLatin_l,chLatin_d,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_l,chLatin_e,chLatin_v,chLatin_e,chLatin_l,chLatin_s, chNull }; // building:levels
static XMLCh szBUILDING_USE[]={chLatin_b,chLatin_u,chLatin_i,chLatin_l,chLatin_d,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_u,chLatin_s,chLatin_e, chNull }; // building:use
static XMLCh szBUIL[]={chLatin_b,chLatin_u,chLatin_i,chLatin_l, chNull }; // buil
static XMLCh szBUNKER_TYPE[]={chLatin_b,chLatin_u,chLatin_n,chLatin_k,chLatin_e,chLatin_r,chUnderscore,chLatin_t,chLatin_y,chLatin_p,chLatin_e, chNull }; // bunker_type
static XMLCh szBUS_STOP[]={chLatin_b,chLatin_u,chLatin_s,chUnderscore,chLatin_s,chLatin_t,chLatin_o,chLatin_p, chNull }; // bus_stop
static XMLCh szBYWAY[]={chLatin_b,chLatin_y,chLatin_w,chLatin_a,chLatin_y, chNull }; // byway
static XMLCh szCALLSIGN[]={chLatin_c,chLatin_a,chLatin_l,chLatin_l,chLatin_s,chLatin_i,chLatin_g,chLatin_n, chNull }; // callsign
static XMLCh szCAPACITY[]={chLatin_c,chLatin_a,chLatin_p,chLatin_a,chLatin_c,chLatin_i,chLatin_t,chLatin_y, chNull }; // capacity
static XMLCh szCENSUS_POPULATION[]={chLatin_c,chLatin_e,chLatin_n,chLatin_s,chLatin_u,chLatin_s,chColon,chLatin_p,chLatin_o,chLatin_p,chLatin_u,chLatin_l,chLatin_a,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // census:population
static XMLCh szCHARGE[]={chLatin_c,chLatin_h,chLatin_a,chLatin_r,chLatin_g,chLatin_e, chNull }; // charge
static XMLCh szCITYRACKS_HOUSENUM[]={chLatin_c,chLatin_i,chLatin_t,chLatin_y,chLatin_r,chLatin_a,chLatin_c,chLatin_k,chLatin_s,chPeriod,chLatin_h,chLatin_o,chLatin_u,chLatin_s,chLatin_e,chLatin_n,chLatin_u,chLatin_m, chNull }; // cityracks.housenum
static XMLCh szCITYRACKS_INSTALLED[]={chLatin_c,chLatin_i,chLatin_t,chLatin_y,chLatin_r,chLatin_a,chLatin_c,chLatin_k,chLatin_s,chPeriod,chLatin_i,chLatin_n,chLatin_s,chLatin_t,chLatin_a,chLatin_l,chLatin_l,chLatin_e,chLatin_d, chNull }; // cityracks.installed
static XMLCh szCITYRACKS_LARGE[]={chLatin_c,chLatin_i,chLatin_t,chLatin_y,chLatin_r,chLatin_a,chLatin_c,chLatin_k,chLatin_s,chPeriod,chLatin_l,chLatin_a,chLatin_r,chLatin_g,chLatin_e, chNull }; // cityracks.large
static XMLCh szCITYRACKS_RACKID[]={chLatin_c,chLatin_i,chLatin_t,chLatin_y,chLatin_r,chLatin_a,chLatin_c,chLatin_k,chLatin_s,chPeriod,chLatin_r,chLatin_a,chLatin_c,chLatin_k,chLatin_i,chLatin_d, chNull }; // cityracks.rackid
static XMLCh szCITYRACKS_SMALL[]={chLatin_c,chLatin_i,chLatin_t,chLatin_y,chLatin_r,chLatin_a,chLatin_c,chLatin_k,chLatin_s,chPeriod,chLatin_s,chLatin_m,chLatin_a,chLatin_l,chLatin_l, chNull }; // cityracks.small
static XMLCh szCITYRACKS_STREET[]={chLatin_c,chLatin_i,chLatin_t,chLatin_y,chLatin_r,chLatin_a,chLatin_c,chLatin_k,chLatin_s,chPeriod,chLatin_s,chLatin_t,chLatin_r,chLatin_e,chLatin_e,chLatin_t, chNull }; // cityracks.street
static XMLCh szCITY[]={chLatin_c,chLatin_i,chLatin_t,chLatin_y, chNull }; // city
static XMLCh szCITY_SERVED[]={chLatin_c,chLatin_i,chLatin_t,chLatin_y,chUnderscore,chLatin_s,chLatin_e,chLatin_r,chLatin_v,chLatin_e,chLatin_d, chNull }; // city_served

static XMLCh szCLOSED[]={chLatin_c,chLatin_l,chLatin_o,chLatin_s,chLatin_e,chLatin_d, chNull }; // closed
static XMLCh szCLOSEST_TOWN[]={chLatin_c,chLatin_l,chLatin_o,chLatin_s,chLatin_e,chLatin_s,chLatin_t,chUnderscore,chLatin_t,chLatin_o,chLatin_w,chLatin_n, chNull }; // closest_town
static XMLCh szCLOSE[]={chLatin_c,chLatin_l,chLatin_o,chLatin_s,chLatin_e, chNull }; // close
static XMLCh szCOLLECTION[]={chLatin_c,chLatin_o,chLatin_l,chLatin_l,chLatin_e,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // collection

static XMLCh szCOLLEGE[]={chLatin_C,chLatin_o,chLatin_l,chLatin_l,chLatin_e,chLatin_g,chLatin_e, chNull }; // College
static XMLCh szCOLOUR[]={chLatin_c,chLatin_o,chLatin_l,chLatin_o,chLatin_u,chLatin_r, chNull }; // colour
static XMLCh szCONGRESS_DISTRICT[]={chLatin_c,chLatin_o,chLatin_n,chLatin_g,chLatin_r,chLatin_e,chLatin_s,chLatin_s,chUnderscore,chLatin_d,chLatin_i,chLatin_s,chLatin_t,chLatin_r,chLatin_i,chLatin_c,chLatin_t, chNull }; // congress_district

static XMLCh szCONSTRUCTION[]={chLatin_c,chLatin_o,chLatin_n,chLatin_s,chLatin_t,chLatin_r,chLatin_u,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // construction
static XMLCh szCOUNTRY[]={chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_r,chLatin_y, chNull }; // country

static XMLCh szCOVERED[]={chLatin_c,chLatin_o,chLatin_v,chLatin_e,chLatin_r,chLatin_e,chLatin_d, chNull }; // covered

static XMLCh szCREATED_BY[]={chLatin_c,chLatin_r,chLatin_e,chLatin_a,chLatin_t,chLatin_e,chLatin_d,chUnderscore,chLatin_b,chLatin_y, chNull }; // created_by
static XMLCh szCROSSING[]={chLatin_c,chLatin_r,chLatin_o,chLatin_s,chLatin_s,chLatin_i,chLatin_n,chLatin_g, chNull }; // crossing
static XMLCh szCROSSING_REF[]={chLatin_c,chLatin_r,chLatin_o,chLatin_s,chLatin_s,chLatin_i,chLatin_n,chLatin_g,chUnderscore,chLatin_r,chLatin_e,chLatin_f, chNull }; // crossing_ref
static XMLCh szCROSS_COUNTY_SKI[]={chLatin_c,chLatin_r,chLatin_o,chLatin_s,chLatin_s,chUnderscore,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y,chUnderscore,chLatin_s,chLatin_k,chLatin_i, chNull }; // cross_county_ski
static XMLCh szCUISINE[]={chLatin_c,chLatin_u,chLatin_i,chLatin_s,chLatin_i,chLatin_n,chLatin_e, chNull }; // cuisine
static XMLCh szCUTTING[]={chLatin_c,chLatin_u,chLatin_t,chLatin_t,chLatin_i,chLatin_n,chLatin_g, chNull }; // cutting
static XMLCh szCYCLEWAY[]={chLatin_c,chLatin_y,chLatin_c,chLatin_l,chLatin_e,chLatin_w,chLatin_a,chLatin_y, chNull }; // cycleway
static XMLCh szDAY_OFF[]={chLatin_d,chLatin_a,chLatin_y,chUnderscore,chLatin_o,chLatin_f,chLatin_f, chNull }; // day_off
static XMLCh szDAY_ON[]={chLatin_d,chLatin_a,chLatin_y,chUnderscore,chLatin_o,chLatin_n, chNull }; // day_on
static XMLCh szDENOMINATION[]={chLatin_d,chLatin_e,chLatin_n,chLatin_o,chLatin_m,chLatin_i,chLatin_n,chLatin_a,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // denomination

static XMLCh szDESCRIPTION[]={chLatin_d,chLatin_e,chLatin_s,chLatin_c,chLatin_r,chLatin_i,chLatin_p,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // description
static XMLCh szDESCRIPTION_EN_BLIND[]={chLatin_d,chLatin_e,chLatin_s,chLatin_c,chLatin_r,chLatin_i,chLatin_p,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chColon,chLatin_e,chLatin_n,chColon,chLatin_b,chLatin_l,chLatin_i,chLatin_n,chLatin_d, chNull }; // description:en:blind
static XMLCh szDISPENSE[]={chLatin_d,chLatin_i,chLatin_s,chLatin_p,chLatin_e,chLatin_n,chLatin_s,chLatin_e, chNull }; // dispense
static XMLCh szDISPENSING[]={chLatin_d,chLatin_i,chLatin_s,chLatin_p,chLatin_e,chLatin_n,chLatin_s,chLatin_i,chLatin_n,chLatin_g, chNull }; // dispensing
static XMLCh szDISUSED[]={chLatin_d,chLatin_i,chLatin_s,chLatin_u,chLatin_s,chLatin_e,chLatin_d, chNull }; // disused
static XMLCh szELECTRIFIED[]={chLatin_e,chLatin_l,chLatin_e,chLatin_c,chLatin_t,chLatin_r,chLatin_i,chLatin_f,chLatin_i,chLatin_e,chLatin_d, chNull }; // electrified
static XMLCh szELE[]={chLatin_e,chLatin_l,chLatin_e, chNull }; // ele
static XMLCh szEMBANKMENT[]={chLatin_e,chLatin_m,chLatin_b,chLatin_a,chLatin_n,chLatin_k,chLatin_m,chLatin_e,chLatin_n,chLatin_t, chNull }; // embankment
static XMLCh szEMBELLISHMENT[]={chLatin_e,chLatin_m,chLatin_b,chLatin_e,chLatin_l,chLatin_l,chLatin_i,chLatin_s,chLatin_h,chLatin_m,chLatin_e,chLatin_n,chLatin_t, chNull }; // embellishment
static XMLCh szEMBELLISHMENT_HEIGHT[]={chLatin_e,chLatin_m,chLatin_b,chLatin_e,chLatin_l,chLatin_l,chLatin_i,chLatin_s,chLatin_h,chLatin_m,chLatin_e,chLatin_n,chLatin_t,chUnderscore,chLatin_h,chLatin_e,chLatin_i,chLatin_g,chLatin_h,chLatin_t, chNull }; // embellishment_height
static XMLCh szEPAPROGRAMM[]={chLatin_E,chLatin_P,chLatin_A,chLatin_P,chLatin_R,chLatin_O,chLatin_G,chLatin_R,chLatin_A,chLatin_M,chLatin_M, chNull }; // EPAPROGRAMM
static XMLCh szFAA[]={chLatin_f,chLatin_a,chLatin_a, chNull }; // faa
static XMLCh szFEE[]={chLatin_f,chLatin_e,chLatin_e, chNull }; // fee
static XMLCh szFENCED[]={chLatin_f,chLatin_e,chLatin_n,chLatin_c,chLatin_e,chLatin_d, chNull }; // fenced
static XMLCh szFIXME[]={chLatin_F,chLatin_I,chLatin_X,chLatin_M,chLatin_E, chNull }; // FIXME
static XMLCh szFOOD[]={chLatin_F,chLatin_o,chLatin_o,chLatin_d, chNull }; // Food
static XMLCh szFOOTWAY[]={chLatin_f,chLatin_o,chLatin_o,chLatin_t,chLatin_w,chLatin_a,chLatin_y, chNull }; // footway
static XMLCh szFOOT[]={chLatin_f,chLatin_o,chLatin_o,chLatin_t, chNull }; // foot
static XMLCh szGATE[]={chLatin_g,chLatin_a,chLatin_t,chLatin_e, chNull }; // gate
static XMLCh szGNIS_CLASS[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_C,chLatin_l,chLatin_a,chLatin_s,chLatin_s, chNull }; // gnis:Class
static XMLCh szGNIS_COUNTY[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_C,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y, chNull }; // gnis:County
static XMLCh szGNIS_COUNTY_ID[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y,chUnderscore,chLatin_i,chLatin_d, chNull }; // gnis:county_id
static XMLCh szGNIS_COUNTY_NAME[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y,chUnderscore,chLatin_n,chLatin_a,chLatin_m,chLatin_e, chNull }; // gnis:county_name
static XMLCh szGNIS_COUNTY_NUM[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_C,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y,chUnderscore,chLatin_n,chLatin_u,chLatin_m, chNull }; // gnis:County_num
static XMLCh szGNIS_CREATED[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_c,chLatin_r,chLatin_e,chLatin_a,chLatin_t,chLatin_e,chLatin_d, chNull }; // gnis:created
static XMLCh szGNIS_EDITED[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_e,chLatin_d,chLatin_i,chLatin_t,chLatin_e,chLatin_d, chNull }; // gnis:edited
static XMLCh szGNIS_FEATURE[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_f,chLatin_e,chLatin_a,chLatin_t,chLatin_u,chLatin_r,chLatin_e, chNull }; // gnis:feature
static XMLCh szGNIS_FEATURE_ID[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_f,chLatin_e,chLatin_a,chLatin_t,chLatin_u,chLatin_r,chLatin_e,chUnderscore,chLatin_i,chLatin_d, chNull }; // gnis:feature_id
static XMLCh szGNIS_FEATURE_TYPE[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_f,chLatin_e,chLatin_a,chLatin_t,chLatin_u,chLatin_r,chLatin_e,chUnderscore,chLatin_t,chLatin_y,chLatin_p,chLatin_e, chNull }; // gnis:feature_type
static XMLCh szGNIS_ID[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_i,chLatin_d, chNull }; // gnis:id
static XMLCh szGNIS_IMPORT_UUID[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_i,chLatin_m,chLatin_p,chLatin_o,chLatin_r,chLatin_t,chUnderscore,chLatin_u,chLatin_u,chLatin_i,chLatin_d, chNull }; // gnis:import_uuid
static XMLCh szGNIS_REVIEWED[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_r,chLatin_e,chLatin_v,chLatin_i,chLatin_e,chLatin_w,chLatin_e,chLatin_d, chNull }; // gnis:reviewed
static XMLCh szGNIS_STATE_ID[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_s,chLatin_t,chLatin_a,chLatin_t,chLatin_e,chUnderscore,chLatin_i,chLatin_d, chNull }; // gnis:state_id
static XMLCh szGNIS_ST_ALPHA[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_S,chLatin_T,chUnderscore,chLatin_a,chLatin_l,chLatin_p,chLatin_h,chLatin_a, chNull }; // gnis:ST_alpha
static XMLCh szGNIS_ST_NUM[]={chLatin_g,chLatin_n,chLatin_i,chLatin_s,chColon,chLatin_S,chLatin_T,chUnderscore,chLatin_n,chLatin_u,chLatin_m, chNull }; // gnis:ST_num
static XMLCh szGROUP[]={chLatin_g,chLatin_r,chLatin_o,chLatin_u,chLatin_p, chNull }; // group
static XMLCh szHEIGHT[]={chLatin_h,chLatin_e,chLatin_i,chLatin_g,chLatin_h,chLatin_t, chNull }; // height
static XMLCh szHGV[]={chLatin_h,chLatin_g,chLatin_v, chNull }; // hgv
static XMLCh szHIGHWAY[]={chLatin_h,chLatin_i,chLatin_g,chLatin_h,chLatin_w,chLatin_a,chLatin_y, chNull }; // highway
static XMLCh szHISTORICAL[]={chLatin_h,chLatin_i,chLatin_s,chLatin_t,chLatin_o,chLatin_r,chLatin_i,chLatin_c,chLatin_a,chLatin_l, chNull }; // historical
static XMLCh szHISTORIC[]={chLatin_h,chLatin_i,chLatin_s,chLatin_t,chLatin_o,chLatin_r,chLatin_i,chLatin_c, chNull }; // historic
static XMLCh szHISTORY[]={chLatin_h,chLatin_i,chLatin_s,chLatin_t,chLatin_o,chLatin_r,chLatin_y, chNull }; // history
static XMLCh szHORSE[]={chLatin_h,chLatin_o,chLatin_r,chLatin_s,chLatin_e, chNull }; // horse
static XMLCh szHOSPITAL[]={chLatin_h,chLatin_o,chLatin_s,chLatin_p,chLatin_i,chLatin_t,chLatin_a,chLatin_l, chNull }; // hospital
static XMLCh szHOURS[]={chLatin_h,chLatin_o,chLatin_u,chLatin_r,chLatin_s, chNull }; // hours
static XMLCh szHOUR_OFF[]={chLatin_h,chLatin_o,chLatin_u,chLatin_r,chUnderscore,chLatin_o,chLatin_f,chLatin_f, chNull }; // hour_off


static XMLCh szHOUR_ON[]={chLatin_h,chLatin_o,chLatin_u,chLatin_r,chUnderscore,chLatin_o,chLatin_n, chNull }; // hour_on
static XMLCh szHUC_CODE[]={chLatin_h,chLatin_u,chLatin_c,chUnderscore,chLatin_c,chLatin_o,chLatin_d,chLatin_e, chNull }; // huc_code
static XMLCh szIATA[]={chLatin_i,chLatin_a,chLatin_t,chLatin_a, chNull }; // iata
static XMLCh szICAO[]={chLatin_i,chLatin_c,chLatin_a,chLatin_o, chNull }; // icao
static XMLCh szIMPORT[]={chLatin_i,chLatin_m,chLatin_p,chLatin_o,chLatin_r,chLatin_t, chNull }; // import
static XMLCh szIMPORT_UUID[]={chLatin_i,chLatin_m,chLatin_p,chLatin_o,chLatin_r,chLatin_t,chUnderscore,chLatin_u,chLatin_u,chLatin_i,chLatin_d, chNull }; // import_uuid
static XMLCh szINFORMATION[]={chLatin_i,chLatin_n,chLatin_f,chLatin_o,chLatin_r,chLatin_m,chLatin_a,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // information
static XMLCh szINTERNET_ACCESS[]={chLatin_i,chLatin_n,chLatin_t,chLatin_e,chLatin_r,chLatin_n,chLatin_e,chLatin_t,chUnderscore,chLatin_a,chLatin_c,chLatin_c,chLatin_e,chLatin_s,chLatin_s, chNull }; // internet_access
static XMLCh szIN[]={chLatin_i,chLatin_n, chNull }; // in

static XMLCh szIS_IN[]={chLatin_i,chLatin_s,chUnderscore,chLatin_i,chLatin_n, chNull }; // is_in
static XMLCh szIS_IN_CONTINENT[]={chLatin_i,chLatin_s,chUnderscore,chLatin_i,chLatin_n,chColon,chLatin_c,chLatin_o,chLatin_n,chLatin_t,chLatin_i,chLatin_n,chLatin_e,chLatin_n,chLatin_t, chNull }; // is_in:continent
static XMLCh szIS_IN_COUNTRY[]={chLatin_i,chLatin_s,chUnderscore,chLatin_i,chLatin_n,chColon,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_r,chLatin_y, chNull }; // is_in:country

static XMLCh szIS_IN_COUNTRY_CODE[]={chLatin_i,chLatin_s,chUnderscore,chLatin_i,chLatin_n,chColon,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_r,chLatin_y,chUnderscore,chLatin_c,chLatin_o,chLatin_d,chLatin_e, chNull }; // is_in:country_code

static XMLCh szIS_IN_ISO_3166_2[]={chLatin_i,chLatin_s,chUnderscore,chLatin_i,chLatin_n,chColon,chLatin_i,chLatin_s,chLatin_o,chUnderscore,chDigit_3,chDigit_1,chDigit_6,chDigit_6,chUnderscore,chDigit_2, chNull }; // is_in:iso_3166_2
static XMLCh szIS_IN_STATE[]={chLatin_i,chLatin_s,chUnderscore,chLatin_i,chLatin_n,chColon,chLatin_s,chLatin_t,chLatin_a,chLatin_t,chLatin_e, chNull }; // is_in:state

static XMLCh szIS_IN_STATE_CODE[]={chLatin_i,chLatin_s,chUnderscore,chLatin_i,chLatin_n,chColon,chLatin_s,chLatin_t,chLatin_a,chLatin_t,chLatin_e,chUnderscore,chLatin_c,chLatin_o,chLatin_d,chLatin_e, chNull }; // is_in:state_code

static XMLCh szJUNCTION[]={chLatin_j,chLatin_u,chLatin_n,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // junction
static XMLCh szKEY[]={chLatin_k,chLatin_e,chLatin_y, chNull }; // key
static XMLCh szLANDUSE[]={chLatin_l,chLatin_a,chLatin_n,chLatin_d,chLatin_u,chLatin_s,chLatin_e, chNull }; // landuse

static XMLCh szLANES[]={chLatin_l,chLatin_a,chLatin_n,chLatin_e,chLatin_s, chNull }; // lanes
static XMLCh szLAYER[]={chLatin_l,chLatin_a,chLatin_y,chLatin_e,chLatin_r, chNull }; // layer
static XMLCh szLAYER_[]={chLatin_l,chLatin_a,chLatin_y,chLatin_e,chLatin_r,chSpace, chNull }; // layer 
static XMLCh szLCN[]={chLatin_l,chLatin_c,chLatin_n, chNull }; // lcn
static XMLCh szLEFT_COUNTY[]={chLatin_l,chLatin_e,chLatin_f,chLatin_t,chColon,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y, chNull }; // left:county

static XMLCh szLEFT_TOWNSHIP[]={chLatin_l,chLatin_e,chLatin_f,chLatin_t,chColon,chLatin_t,chLatin_o,chLatin_w,chLatin_n,chLatin_s,chLatin_h,chLatin_i,chLatin_p, chNull }; // left:township


static XMLCh szLEISURE[]={chLatin_l,chLatin_e,chLatin_i,chLatin_s,chLatin_u,chLatin_r,chLatin_e, chNull }; // leisure
static XMLCh szLEVEL[]={chLatin_l,chLatin_e,chLatin_v,chLatin_e,chLatin_l, chNull }; // level
static XMLCh szLINES[]={chLatin_l,chLatin_i,chLatin_n,chLatin_e,chLatin_s, chNull }; // lines

static XMLCh szLINE[]={chLatin_l,chLatin_i,chLatin_n,chLatin_e, chNull }; // line
static XMLCh szLIVING_STREET[]={chLatin_l,chLatin_i,chLatin_v,chLatin_i,chLatin_n,chLatin_g,chUnderscore,chLatin_s,chLatin_t,chLatin_r,chLatin_e,chLatin_e,chLatin_t, chNull }; // living_street
static XMLCh szLOC_NAME[]={chLatin_l,chLatin_o,chLatin_c,chUnderscore,chLatin_n,chLatin_a,chLatin_m,chLatin_e, chNull }; // loc_name
static XMLCh szMADISON[]={chLatin_m,chLatin_a,chLatin_d,chLatin_i,chLatin_s,chLatin_o,chLatin_n, chNull }; // madison
static XMLCh szMAN_MADE[]={chLatin_m,chLatin_a,chLatin_n,chUnderscore,chLatin_m,chLatin_a,chLatin_d,chLatin_e, chNull }; // man_made
static XMLCh szMARITIME[]={chLatin_m,chLatin_a,chLatin_r,chLatin_i,chLatin_t,chLatin_i,chLatin_m,chLatin_e, chNull }; // maritime

static XMLCh szMARKED_TRAIL[]={chLatin_m,chLatin_a,chLatin_r,chLatin_k,chLatin_e,chLatin_d,chUnderscore,chLatin_t,chLatin_r,chLatin_a,chLatin_i,chLatin_l, chNull }; // marked_trail
static XMLCh szMAXHEIGHT[]={chLatin_m,chLatin_a,chLatin_x,chLatin_h,chLatin_e,chLatin_i,chLatin_g,chLatin_h,chLatin_t, chNull }; // maxheight


static XMLCh szMAXHEIGHT_FEET[]={chLatin_m,chLatin_a,chLatin_x,chLatin_h,chLatin_e,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chColon,chLatin_f,chLatin_e,chLatin_e,chLatin_t, chNull }; // maxheight:feet
static XMLCh szMAXSPEED[]={chLatin_m,chLatin_a,chLatin_x,chLatin_s,chLatin_p,chLatin_e,chLatin_e,chLatin_d, chNull }; // maxspeed
static XMLCh szMAXWT[]={chLatin_m,chLatin_a,chLatin_x,chLatin_w,chLatin_t, chNull }; // maxwt

static XMLCh szMILITARY[]={chLatin_m,chLatin_i,chLatin_l,chLatin_i,chLatin_t,chLatin_a,chLatin_r,chLatin_y, chNull }; // military
static XMLCh szMINI_ROUNDABOUT[]={chLatin_m,chLatin_i,chLatin_n,chLatin_i,chUnderscore,chLatin_r,chLatin_o,chLatin_u,chLatin_n,chLatin_d,chLatin_a,chLatin_b,chLatin_o,chLatin_u,chLatin_t, chNull }; // mini_roundabout

static XMLCh szMODIFIER[]={chLatin_m,chLatin_o,chLatin_d,chLatin_i,chLatin_f,chLatin_i,chLatin_e,chLatin_r, chNull }; // modifier
static XMLCh szMOTORCAR[]={chLatin_m,chLatin_o,chLatin_t,chLatin_o,chLatin_r,chLatin_c,chLatin_a,chLatin_r, chNull }; // motorcar
static XMLCh szMOTORWAY[]={chLatin_m,chLatin_o,chLatin_t,chLatin_o,chLatin_r,chLatin_w,chLatin_a,chLatin_y, chNull }; // motorway
static XMLCh szMOTORWAY_JUNCTION[]={chLatin_m,chLatin_o,chLatin_t,chLatin_o,chLatin_r,chLatin_w,chLatin_a,chLatin_y,chUnderscore,chLatin_j,chLatin_u,chLatin_n,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // motorway_junction
static XMLCh szMOTORWAY_LINK[]={chLatin_m,chLatin_o,chLatin_t,chLatin_o,chLatin_r,chLatin_w,chLatin_a,chLatin_y,chUnderscore,chLatin_l,chLatin_i,chLatin_n,chLatin_k, chNull }; // motorway_link
static XMLCh szNAPE[]={chLatin_n,chLatin_a,chLatin_p,chLatin_e, chNull }; // nape
static XMLCh szNARROW[]={chLatin_n,chLatin_a,chLatin_r,chLatin_r,chLatin_o,chLatin_w, chNull }; // narrow
static XMLCh szNATURAL[]={chLatin_n,chLatin_a,chLatin_t,chLatin_u,chLatin_r,chLatin_a,chLatin_l, chNull }; // natural
static XMLCh szNATURA[]={chLatin_n,chLatin_a,chLatin_t,chLatin_u,chLatin_r,chLatin_a, chNull }; // natura
static XMLCh szNATURE[]={chLatin_n,chLatin_a,chLatin_t,chLatin_u,chLatin_r,chLatin_e, chNull }; // nature
static XMLCh szNAT_NAME[]={chLatin_n,chLatin_a,chLatin_t,chUnderscore,chLatin_n,chLatin_a,chLatin_m,chLatin_e, chNull }; // nat_name
static XMLCh szNAT_REF[]={chLatin_n,chLatin_a,chLatin_t,chUnderscore,chLatin_r,chLatin_e,chLatin_f, chNull }; // nat_ref
static XMLCh szNEIGHBORHOOD[]={chLatin_n,chLatin_e,chLatin_i,chLatin_g,chLatin_h,chLatin_b,chLatin_o,chLatin_r,chLatin_h,chLatin_o,chLatin_o,chLatin_d, chNull }; // neighborhood
static XMLCh szNETWORK[]={chLatin_n,chLatin_e,chLatin_t,chLatin_w,chLatin_o,chLatin_r,chLatin_k, chNull }; // network

static XMLCh szNIST_FIPS_CODE[]={chLatin_n,chLatin_i,chLatin_s,chLatin_t,chColon,chLatin_f,chLatin_i,chLatin_p,chLatin_s,chUnderscore,chLatin_c,chLatin_o,chLatin_d,chLatin_e, chNull }; // nist:fips_code

static XMLCh szNIST_STATE_FIPS[]={chLatin_n,chLatin_i,chLatin_s,chLatin_t,chColon,chLatin_s,chLatin_t,chLatin_a,chLatin_t,chLatin_e,chUnderscore,chLatin_f,chLatin_i,chLatin_p,chLatin_s, chNull }; // nist:state_fips
static XMLCh szNOEXIT[]={chLatin_n,chLatin_o,chLatin_e,chLatin_x,chLatin_i,chLatin_t, chNull }; // noexit
static XMLCh szNONAME[]={chLatin_n,chLatin_o,chLatin_n,chLatin_a,chLatin_m,chLatin_e, chNull }; // noname

static XMLCh szNOTE[]={chLatin_n,chLatin_o,chLatin_t,chLatin_e, chNull }; // note
static XMLCh szNOTE_2[]={chLatin_n,chLatin_o,chLatin_t,chLatin_e,chUnderscore,chDigit_2, chNull }; // note_2
static XMLCh szNYDEC_LANDS_CATEGORY[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_C,chLatin_A,chLatin_T,chLatin_E,chLatin_G,chLatin_O,chLatin_R,chLatin_Y, chNull }; // NYDEC_Lands:CATEGORY
static XMLCh szNYDEC_LANDS_COUNTY[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_C,chLatin_O,chLatin_U,chLatin_N,chLatin_T,chLatin_Y, chNull }; // NYDEC_Lands:COUNTY
static XMLCh szNYDEC_LANDS_DESCRIPTIO[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_D,chLatin_E,chLatin_S,chLatin_C,chLatin_R,chLatin_I,chLatin_P,chLatin_T,chLatin_I,chLatin_O, chNull }; // NYDEC_Lands:DESCRIPTIO
static XMLCh szNYDEC_LANDS_FACILITY[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_F,chLatin_A,chLatin_C,chLatin_I,chLatin_L,chLatin_I,chLatin_T,chLatin_Y, chNull }; // NYDEC_Lands:FACILITY
static XMLCh szNYDEC_LANDS_FACILITY_N[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_F,chLatin_A,chLatin_C,chLatin_I,chLatin_L,chLatin_I,chLatin_T,chLatin_Y,chUnderscore,chLatin_N, chNull }; // NYDEC_Lands:FACILITY_N
static XMLCh szNYDEC_LANDS_LANDS_UID[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_L,chLatin_A,chLatin_N,chLatin_D,chLatin_S,chUnderscore,chLatin_U,chLatin_I,chLatin_D, chNull }; // NYDEC_Lands:LANDS_UID
static XMLCh szNYDEC_LANDS_OBJECTID[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_O,chLatin_B,chLatin_J,chLatin_E,chLatin_C,chLatin_T,chLatin_I,chLatin_D, chNull }; // NYDEC_Lands:OBJECTID
static XMLCh szNYDEC_LANDS_OFFICE[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_O,chLatin_F,chLatin_F,chLatin_I,chLatin_C,chLatin_E, chNull }; // NYDEC_Lands:OFFICE
static XMLCh szNYDEC_LANDS_PUBLICUSE[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_P,chLatin_U,chLatin_B,chLatin_L,chLatin_I,chLatin_C,chLatin_U,chLatin_S,chLatin_E, chNull }; // NYDEC_Lands:PUBLICUSE
static XMLCh szNYDEC_LANDS_REGION[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_R,chLatin_E,chLatin_G,chLatin_I,chLatin_O,chLatin_N, chNull }; // NYDEC_Lands:REGION
static XMLCh szNYDEC_LANDS_SOURCE[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_S,chLatin_O,chLatin_U,chLatin_R,chLatin_C,chLatin_E, chNull }; // NYDEC_Lands:SOURCE
static XMLCh szNYDEC_LANDS_UMP[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_U,chLatin_M,chLatin_P, chNull }; // NYDEC_Lands:UMP
static XMLCh szNYDEC_LANDS_UNIT[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_U,chLatin_N,chLatin_I,chLatin_T, chNull }; // NYDEC_Lands:UNIT
static XMLCh szNYDEC_LANDS_UPDATE_[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_U,chLatin_P,chLatin_D,chLatin_A,chLatin_T,chLatin_E,chUnderscore, chNull }; // NYDEC_Lands:UPDATE_
static XMLCh szNYDEC_LANDS_URL[]={chLatin_N,chLatin_Y,chLatin_D,chLatin_E,chLatin_C,chUnderscore,chLatin_L,chLatin_a,chLatin_n,chLatin_d,chLatin_s,chColon,chLatin_U,chLatin_R,chLatin_L, chNull }; // NYDEC_Lands:URL
static XMLCh szOLD_NAME[]={chLatin_o,chLatin_l,chLatin_d,chUnderscore,chLatin_n,chLatin_a,chLatin_m,chLatin_e, chNull }; // old_name
static XMLCh szONEWAY[]={chLatin_o,chLatin_n,chLatin_e,chLatin_w,chLatin_a,chLatin_y, chNull }; // oneway
static XMLCh szONEWAY_[]={chLatin_o,chLatin_n,chLatin_e,chLatin_w,chLatin_a,chLatin_y,chColon, chNull }; // oneway:
static XMLCh szONE[]={chLatin_o,chLatin_n,chLatin_e, chNull }; // one
static XMLCh szOPENING_DATE[]={chLatin_o,chLatin_p,chLatin_e,chLatin_n,chLatin_i,chLatin_n,chLatin_g,chSpace,chLatin_d,chLatin_a,chLatin_t,chLatin_e, chNull }; // opening date
static XMLCh szOPENING_HOURS[]={chLatin_o,chLatin_p,chLatin_e,chLatin_n,chLatin_i,chLatin_n,chLatin_g,chUnderscore,chLatin_h,chLatin_o,chLatin_u,chLatin_r,chLatin_s, chNull }; // opening_hours
static XMLCh szOPERATOR[]={chLatin_o,chLatin_p,chLatin_e,chLatin_r,chLatin_a,chLatin_t,chLatin_o,chLatin_r, chNull }; // operator

static XMLCh szOWNER[]={chLatin_o,chLatin_w,chLatin_n,chLatin_e,chLatin_r, chNull }; // owner
static XMLCh szPARKING[]={chLatin_p,chLatin_a,chLatin_r,chLatin_k,chLatin_i,chLatin_n,chLatin_g, chNull }; // parking
static XMLCh szPARK[]={chLatin_P,chLatin_a,chLatin_r,chLatin_k, chNull }; // Park

static XMLCh szPASDA_NAMED[]={chLatin_p,chLatin_a,chLatin_s,chLatin_d,chLatin_a,chColon,chLatin_N,chLatin_A,chLatin_M,chLatin_E,chLatin_D, chNull }; // pasda:NAMED
static XMLCh szPASDA_SEGID[]={chLatin_p,chLatin_a,chLatin_s,chLatin_d,chLatin_a,chColon,chLatin_S,chLatin_E,chLatin_G,chLatin_I,chLatin_D, chNull }; // pasda:SEGID
static XMLCh szPATH[]={chLatin_p,chLatin_a,chLatin_t,chLatin_h, chNull }; // path
static XMLCh szPAYMENT_COINS[]={chLatin_p,chLatin_a,chLatin_y,chLatin_m,chLatin_e,chLatin_n,chLatin_t,chColon,chLatin_c,chLatin_o,chLatin_i,chLatin_n,chLatin_s, chNull }; // payment:coins
static XMLCh szPAYMENT_CREDIT_CARDS[]={chLatin_p,chLatin_a,chLatin_y,chLatin_m,chLatin_e,chLatin_n,chLatin_t,chColon,chLatin_c,chLatin_r,chLatin_e,chLatin_d,chLatin_i,chLatin_t,chUnderscore,chLatin_c,chLatin_a,chLatin_r,chLatin_d,chLatin_s, chNull }; // payment:credit_cards
static XMLCh szPEDESTRIAN[]={chLatin_p,chLatin_e,chLatin_d,chLatin_e,chLatin_s,chLatin_t,chLatin_r,chLatin_i,chLatin_a,chLatin_n, chNull }; // pedestrian
static XMLCh szPERMIT[]={chLatin_p,chLatin_e,chLatin_r,chLatin_m,chLatin_i,chLatin_t, chNull }; // permit
static XMLCh szPHONE[]={chLatin_p,chLatin_h,chLatin_o,chLatin_n,chLatin_e, chNull }; // phone

static XMLCh szPLACE[]={chLatin_p,chLatin_l,chLatin_a,chLatin_c,chLatin_e, chNull }; // place

static XMLCh szPLACE_NAME[]={chLatin_p,chLatin_l,chLatin_a,chLatin_c,chLatin_e,chUnderscore,chLatin_n,chLatin_a,chLatin_m,chLatin_e, chNull }; // place_name
static XMLCh szPLATFORM[]={chLatin_p,chLatin_l,chLatin_a,chLatin_t,chLatin_f,chLatin_o,chLatin_r,chLatin_m, chNull }; // platform
static XMLCh szPOINT_1[]={chLatin_p,chLatin_o,chLatin_i,chLatin_n,chLatin_t,chSpace,chDigit_1, chNull }; // point 1
static XMLCh szPOPULATION[]={chLatin_p,chLatin_o,chLatin_p,chLatin_u,chLatin_l,chLatin_a,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // population
static XMLCh szPOWER[]={chLatin_p,chLatin_o,chLatin_w,chLatin_e,chLatin_r, chNull }; // power
static XMLCh szPOWER_SOURCE[]={chLatin_p,chLatin_o,chLatin_w,chLatin_e,chLatin_r,chUnderscore,chLatin_s,chLatin_o,chLatin_u,chLatin_r,chLatin_c,chLatin_e, chNull }; // power_source
static XMLCh szPRIMARY[]={chLatin_p,chLatin_r,chLatin_i,chLatin_m,chLatin_a,chLatin_r,chLatin_y, chNull }; // primary
static XMLCh szPRIMARY_LINK[]={chLatin_p,chLatin_r,chLatin_i,chLatin_m,chLatin_a,chLatin_r,chLatin_y,chUnderscore,chLatin_l,chLatin_i,chLatin_n,chLatin_k, chNull }; // primary_link
static XMLCh szPRIMARY_RESIDENTIAL[]={chLatin_p,chLatin_r,chLatin_i,chLatin_m,chLatin_a,chLatin_r,chLatin_y,chSemiColon,chLatin_r,chLatin_e,chLatin_s,chLatin_i,chLatin_d,chLatin_e,chLatin_n,chLatin_t,chLatin_i,chLatin_a,chLatin_l, chNull }; // primary;residential
static XMLCh szPRIVATE[]={chLatin_p,chLatin_r,chLatin_i,chLatin_v,chLatin_a,chLatin_t,chLatin_e, chNull }; // private
static XMLCh szPSV[]={chLatin_p,chLatin_s,chLatin_v, chNull }; // psv
static XMLCh szRADAR_TRANSPONDER[]={chLatin_r,chLatin_a,chLatin_d,chLatin_a,chLatin_r,chUnderscore,chLatin_t,chLatin_r,chLatin_a,chLatin_n,chLatin_s,chLatin_p,chLatin_o,chLatin_n,chLatin_d,chLatin_e,chLatin_r, chNull }; // radar_transponder
static XMLCh szRADNOR_BY_TWP[]={chLatin_r,chLatin_a,chLatin_d,chLatin_n,chLatin_o,chLatin_r,chColon,chLatin_B,chLatin_Y,chUnderscore,chLatin_T,chLatin_W,chLatin_P, chNull }; // radnor:BY_TWP
static XMLCh szRADNOR_ID[]={chLatin_r,chLatin_a,chLatin_d,chLatin_n,chLatin_o,chLatin_r,chColon,chLatin_I,chLatin_D, chNull }; // radnor:ID

static XMLCh szRAILWAY[]={chLatin_r,chLatin_a,chLatin_i,chLatin_l,chLatin_w,chLatin_a,chLatin_y, chNull }; // railway
static XMLCh szRCN[]={chLatin_r,chLatin_c,chLatin_n, chNull }; // rcn
static XMLCh szRCN_NAME[]={chLatin_r,chLatin_c,chLatin_n,chUnderscore,chLatin_n,chLatin_a,chLatin_m,chLatin_e, chNull }; // rcn_name
static XMLCh szRECYCLING_BATTERIES[]={chLatin_r,chLatin_e,chLatin_c,chLatin_y,chLatin_c,chLatin_l,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_b,chLatin_a,chLatin_t,chLatin_t,chLatin_e,chLatin_r,chLatin_i,chLatin_e,chLatin_s, chNull }; // recycling:batteries
static XMLCh szRECYCLING_CANS[]={chLatin_r,chLatin_e,chLatin_c,chLatin_y,chLatin_c,chLatin_l,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_c,chLatin_a,chLatin_n,chLatin_s, chNull }; // recycling:cans
static XMLCh szRECYCLING_CARDBOARD[]={chLatin_r,chLatin_e,chLatin_c,chLatin_y,chLatin_c,chLatin_l,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_c,chLatin_a,chLatin_r,chLatin_d,chLatin_b,chLatin_o,chLatin_a,chLatin_r,chLatin_d, chNull }; // recycling:cardboard
static XMLCh szRECYCLING_CLOTHES[]={chLatin_r,chLatin_e,chLatin_c,chLatin_y,chLatin_c,chLatin_l,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_c,chLatin_l,chLatin_o,chLatin_t,chLatin_h,chLatin_e,chLatin_s, chNull }; // recycling:clothes
static XMLCh szRECYCLING_GLASS[]={chLatin_r,chLatin_e,chLatin_c,chLatin_y,chLatin_c,chLatin_l,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_g,chLatin_l,chLatin_a,chLatin_s,chLatin_s, chNull }; // recycling:glass
static XMLCh szRECYCLING_PAPER[]={chLatin_r,chLatin_e,chLatin_c,chLatin_y,chLatin_c,chLatin_l,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_p,chLatin_a,chLatin_p,chLatin_e,chLatin_r, chNull }; // recycling:paper
static XMLCh szRECYCLING_PLASTIC[]={chLatin_r,chLatin_e,chLatin_c,chLatin_y,chLatin_c,chLatin_l,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_p,chLatin_l,chLatin_a,chLatin_s,chLatin_t,chLatin_i,chLatin_c, chNull }; // recycling:plastic
static XMLCh szRECYCLING_SCRAP_METAL[]={chLatin_r,chLatin_e,chLatin_c,chLatin_y,chLatin_c,chLatin_l,chLatin_i,chLatin_n,chLatin_g,chColon,chLatin_s,chLatin_c,chLatin_r,chLatin_a,chLatin_p,chUnderscore,chLatin_m,chLatin_e,chLatin_t,chLatin_a,chLatin_l, chNull }; // recycling:scrap_metal

static XMLCh szREF_1[]={chLatin_r,chLatin_e,chLatin_f,chUnderscore,chDigit_1, chNull }; // ref_1
static XMLCh szREF_FUTURE[]={chLatin_r,chLatin_e,chLatin_f,chColon,chLatin_f,chLatin_u,chLatin_t,chLatin_u,chLatin_r,chLatin_e, chNull }; // ref:future
static XMLCh szREG_NAME[]={chLatin_r,chLatin_e,chLatin_g,chUnderscore,chLatin_n,chLatin_a,chLatin_m,chLatin_e, chNull }; // reg_name
static XMLCh szRELIGION[]={chLatin_r,chLatin_e,chLatin_l,chLatin_i,chLatin_g,chLatin_i,chLatin_o,chLatin_n, chNull }; // religion
static XMLCh szRESIDENCE_TYPE[]={chLatin_r,chLatin_e,chLatin_s,chLatin_i,chLatin_d,chLatin_e,chLatin_n,chLatin_c,chLatin_e,chColon,chLatin_t,chLatin_y,chLatin_p,chLatin_e, chNull }; // residence:type
static XMLCh szRESIDENTIAL[]={chLatin_r,chLatin_e,chLatin_s,chLatin_i,chLatin_d,chLatin_e,chLatin_n,chLatin_t,chLatin_i,chLatin_a,chLatin_l, chNull }; // residential

static XMLCh szRESTRICTION[]={chLatin_r,chLatin_e,chLatin_s,chLatin_t,chLatin_r,chLatin_i,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // restriction
static XMLCh szRE[]={chLatin_r,chLatin_e, chNull }; // re

static XMLCh szRIGHT_COUNTY[]={chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chColon,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y, chNull }; // right:county

static XMLCh szRIGHT_STATE[]={chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chColon,chLatin_s,chLatin_t,chLatin_a,chLatin_t,chLatin_e, chNull }; // right:state
static XMLCh szROAD[]={chLatin_r,chLatin_o,chLatin_a,chLatin_d, chNull }; // road
static XMLCh szROA[]={chLatin_r,chLatin_o,chLatin_a, chNull }; // roa
static XMLCh szROLE[]={chLatin_r,chLatin_o,chLatin_l,chLatin_e, chNull }; // role

static XMLCh szROUTE[]={chLatin_r,chLatin_o,chLatin_u,chLatin_t,chLatin_e, chNull }; // route
static XMLCh szROUTE_REF[]={chLatin_r,chLatin_o,chLatin_u,chLatin_t,chLatin_e,chUnderscore,chLatin_r,chLatin_e,chLatin_f, chNull }; // route_ref
static XMLCh szRUINS[]={chLatin_r,chLatin_u,chLatin_i,chLatin_n,chLatin_s, chNull }; // ruins
static XMLCh szR[]={chLatin_r, chNull }; // r
static XMLCh szSAC_SCALE[]={chLatin_s,chLatin_a,chLatin_c,chUnderscore,chLatin_s,chLatin_c,chLatin_a,chLatin_l,chLatin_e, chNull }; // sac_scale
static XMLCh szSECONDARY[]={chLatin_s,chLatin_e,chLatin_c,chLatin_o,chLatin_n,chLatin_d,chLatin_a,chLatin_r,chLatin_y, chNull }; // secondary
static XMLCh szSECONDARY_LINK[]={chLatin_s,chLatin_e,chLatin_c,chLatin_o,chLatin_n,chLatin_d,chLatin_a,chLatin_r,chLatin_y,chUnderscore,chLatin_l,chLatin_i,chLatin_n,chLatin_k, chNull }; // secondary_link
static XMLCh szSEGREGATED[]={chLatin_s,chLatin_e,chLatin_g,chLatin_r,chLatin_e,chLatin_g,chLatin_a,chLatin_t,chLatin_e,chLatin_d, chNull }; // segregated
static XMLCh szSERVICES[]={chLatin_s,chLatin_e,chLatin_r,chLatin_v,chLatin_i,chLatin_c,chLatin_e,chLatin_s, chNull }; // services
static XMLCh szSERVICE[]={chLatin_s,chLatin_e,chLatin_r,chLatin_v,chLatin_i,chLatin_c,chLatin_e, chNull }; // service
static XMLCh szSERVICE__RESIDENTIAL[]={chLatin_s,chLatin_e,chLatin_r,chLatin_v,chLatin_i,chLatin_c,chLatin_e,chSemiColon,chSpace,chLatin_r,chLatin_e,chLatin_s,chLatin_i,chLatin_d,chLatin_e,chLatin_n,chLatin_t,chLatin_i,chLatin_a,chLatin_l, chNull }; // service; residential
static XMLCh szSERVICE__RESIDENTIAL__RESIDENTIAL[]={chLatin_s,chLatin_e,chLatin_r,chLatin_v,chLatin_i,chLatin_c,chLatin_e,chSemiColon,chSpace,chLatin_r,chLatin_e,chLatin_s,chLatin_i,chLatin_d,chLatin_e,chLatin_n,chLatin_t,chLatin_i,chLatin_a,chLatin_l,chSemiColon,chSpace,chLatin_r,chLatin_e,chLatin_s,chLatin_i,chLatin_d,chLatin_e,chLatin_n,chLatin_t,chLatin_i,chLatin_a,chLatin_l, chNull }; // service; residential; residential
static XMLCh szSHELTER[]={chLatin_s,chLatin_h,chLatin_e,chLatin_l,chLatin_t,chLatin_e,chLatin_r, chNull }; // shelter
static XMLCh szSHOPE[]={chLatin_s,chLatin_h,chLatin_o,chLatin_p,chLatin_e, chNull }; // shope

static XMLCh szSHOP[]={chLatin_s,chLatin_h,chLatin_o,chLatin_p, chNull }; // shop
static XMLCh szSIDEWALK[]={chLatin_s,chLatin_i,chLatin_d,chLatin_e,chLatin_w,chLatin_a,chLatin_l,chLatin_k, chNull }; // sidewalk
static XMLCh szSIGN[]={chLatin_s,chLatin_i,chLatin_g,chLatin_n, chNull }; // sign
static XMLCh szSKI[]={chLatin_s,chLatin_k,chLatin_i, chNull }; // ski
static XMLCh szSMOOTHNESS[]={chLatin_s,chLatin_m,chLatin_o,chLatin_o,chLatin_t,chLatin_h,chLatin_n,chLatin_e,chLatin_s,chLatin_s, chNull }; // smoothness
static XMLCh szSNOWMOBILE[]={chLatin_s,chLatin_n,chLatin_o,chLatin_w,chLatin_m,chLatin_o,chLatin_b,chLatin_i,chLatin_l,chLatin_e, chNull }; // snowmobile


static XMLCh szSOURCE_REF[]={chLatin_s,chLatin_o,chLatin_u,chLatin_r,chLatin_c,chLatin_e,chUnderscore,chLatin_r,chLatin_e,chLatin_f, chNull }; // source_ref
static XMLCh szSPORT[]={chLatin_s,chLatin_p,chLatin_o,chLatin_r,chLatin_t, chNull }; // sport
static XMLCh szSTARS[]={chLatin_s,chLatin_t,chLatin_a,chLatin_r,chLatin_s, chNull }; // stars

static XMLCh szSTATE[]={chLatin_s,chLatin_t,chLatin_a,chLatin_t,chLatin_e, chNull }; // state
static XMLCh szSTATE_CAPITAL[]={chLatin_s,chLatin_t,chLatin_a,chLatin_t,chLatin_e,chUnderscore,chLatin_c,chLatin_a,chLatin_p,chLatin_i,chLatin_t,chLatin_a,chLatin_l, chNull }; // state_capital

static XMLCh szSTATE_ID[]={chLatin_s,chLatin_t,chLatin_a,chLatin_t,chLatin_e,chUnderscore,chLatin_i,chLatin_d, chNull }; // state_id
static XMLCh szSTEPS[]={chLatin_s,chLatin_t,chLatin_e,chLatin_p,chLatin_s, chNull }; // steps
static XMLCh szSTEP_COUNT[]={chLatin_s,chLatin_t,chLatin_e,chLatin_p,chUnderscore,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t, chNull }; // step_count
static XMLCh szSTOP[]={chLatin_s,chLatin_t,chLatin_o,chLatin_p, chNull }; // stop
static XMLCh szSTOP_GOODLEY_ROAD[]={chLatin_s,chLatin_t,chLatin_o,chLatin_p,chComma,chLatin_G,chLatin_o,chLatin_o,chLatin_d,chLatin_l,chLatin_e,chLatin_y,chSpace,chLatin_R,chLatin_o,chLatin_a,chLatin_d, chNull }; // stop,Goodley Road
static XMLCh szSTORE[]={chLatin_s,chLatin_t,chLatin_o,chLatin_r,chLatin_e, chNull }; // store
static XMLCh szSUBWAY[]={chLatin_s,chLatin_u,chLatin_b,chLatin_w,chLatin_a,chLatin_y, chNull }; // subway

static XMLCh szSURFACE[]={chLatin_s,chLatin_u,chLatin_r,chLatin_f,chLatin_a,chLatin_c,chLatin_e, chNull }; // surface

static XMLCh szSYMBOL[]={chLatin_s,chLatin_y,chLatin_m,chLatin_b,chLatin_o,chLatin_l, chNull }; // symbol
static XMLCh szTAB[]={chLatin_t,chLatin_a,chLatin_b, chNull }; // tab
static XMLCh szTERTIARY[]={chLatin_t,chLatin_e,chLatin_r,chLatin_t,chLatin_i,chLatin_a,chLatin_r,chLatin_y, chNull }; // tertiary
static XMLCh szTERTIARY_LINK[]={chLatin_t,chLatin_e,chLatin_r,chLatin_t,chLatin_i,chLatin_a,chLatin_r,chLatin_y,chUnderscore,chLatin_l,chLatin_i,chLatin_n,chLatin_k, chNull }; // tertiary_link
static XMLCh szTERTIARY__RESIDENTIAL[]={chLatin_t,chLatin_e,chLatin_r,chLatin_t,chLatin_i,chLatin_a,chLatin_r,chLatin_y,chSemiColon,chSpace,chLatin_r,chLatin_e,chLatin_s,chLatin_i,chLatin_d,chLatin_e,chLatin_n,chLatin_t,chLatin_i,chLatin_a,chLatin_l, chNull }; // tertiary; residential
static XMLCh szTIDAL[]={chLatin_t,chLatin_i,chLatin_d,chLatin_a,chLatin_l, chNull }; // tidal
static XMLCh szTIGERLSOURCE[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chLatin_L,chLatin_s,chLatin_o,chLatin_u,chLatin_r,chLatin_c,chLatin_e, chNull }; // tigerLsource
static XMLCh szTIGER_CFCC[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_c,chLatin_f,chLatin_c,chLatin_c, chNull }; // tiger:cfcc

static XMLCh szTIGER_CLASSFP[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_C,chLatin_L,chLatin_A,chLatin_S,chLatin_S,chLatin_F,chLatin_P, chNull }; // tiger:CLASSFP
static XMLCh szTIGER_COUNTY[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y, chNull }; // tiger:county
static XMLCh szTIGER_CPI[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_C,chLatin_P,chLatin_I, chNull }; // tiger:CPI


static XMLCh szTIGER_FUNCSTAT[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_F,chLatin_U,chLatin_N,chLatin_C,chLatin_S,chLatin_T,chLatin_A,chLatin_T, chNull }; // tiger:FUNCSTAT
static XMLCh szTIGER_LSAD[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_L,chLatin_S,chLatin_A,chLatin_D, chNull }; // tiger:LSAD

static XMLCh szTIGER_MTFCC[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_M,chLatin_T,chLatin_F,chLatin_C,chLatin_C, chNull }; // tiger:MTFCC


static XMLCh szTIGER_NAMELSAD[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_N,chLatin_A,chLatin_M,chLatin_E,chLatin_L,chLatin_S,chLatin_A,chLatin_D, chNull }; // tiger:NAMELSAD

static XMLCh szTIGER_NAME[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_N,chLatin_A,chLatin_M,chLatin_E, chNull }; // tiger:NAME
static XMLCh szTIGER_NAME_BASE[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_b,chLatin_a,chLatin_s,chLatin_e, chNull }; // tiger:name_base
static XMLCh szTIGER_NAME_BASE_1[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_b,chLatin_a,chLatin_s,chLatin_e,chUnderscore,chDigit_1, chNull }; // tiger:name_base_1
static XMLCh szTIGER_NAME_BASE_2[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_b,chLatin_a,chLatin_s,chLatin_e,chUnderscore,chDigit_2, chNull }; // tiger:name_base_2
static XMLCh szTIGER_NAME_BASE_3[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_b,chLatin_a,chLatin_s,chLatin_e,chUnderscore,chDigit_3, chNull }; // tiger:name_base_3
static XMLCh szTIGER_NAME_BASE_4[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_b,chLatin_a,chLatin_s,chLatin_e,chUnderscore,chDigit_4, chNull }; // tiger:name_base_4
static XMLCh szTIGER_NAME_BASE_5[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_b,chLatin_a,chLatin_s,chLatin_e,chUnderscore,chDigit_5, chNull }; // tiger:name_base_5
static XMLCh szTIGER_NAME_DIRECTION_PREFIX[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_d,chLatin_i,chLatin_r,chLatin_e,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chUnderscore,chLatin_p,chLatin_r,chLatin_e,chLatin_f,chLatin_i,chLatin_x, chNull }; // tiger:name_direction_prefix
static XMLCh szTIGER_NAME_DIRECTION_PREFIX_1[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_d,chLatin_i,chLatin_r,chLatin_e,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chUnderscore,chLatin_p,chLatin_r,chLatin_e,chLatin_f,chLatin_i,chLatin_x,chUnderscore,chDigit_1, chNull }; // tiger:name_direction_prefix_1
static XMLCh szTIGER_NAME_DIRECTION_PREFIX_2[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_d,chLatin_i,chLatin_r,chLatin_e,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chUnderscore,chLatin_p,chLatin_r,chLatin_e,chLatin_f,chLatin_i,chLatin_x,chUnderscore,chDigit_2, chNull }; // tiger:name_direction_prefix_2
static XMLCh szTIGER_NAME_DIRECTION_PREFIX_3[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_d,chLatin_i,chLatin_r,chLatin_e,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chUnderscore,chLatin_p,chLatin_r,chLatin_e,chLatin_f,chLatin_i,chLatin_x,chUnderscore,chDigit_3, chNull }; // tiger:name_direction_prefix_3
static XMLCh szTIGER_NAME_DIRECTION_PREFIX_4[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_d,chLatin_i,chLatin_r,chLatin_e,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chUnderscore,chLatin_p,chLatin_r,chLatin_e,chLatin_f,chLatin_i,chLatin_x,chUnderscore,chDigit_4, chNull }; // tiger:name_direction_prefix_4
static XMLCh szTIGER_NAME_DIRECTION_SUFFIX[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_d,chLatin_i,chLatin_r,chLatin_e,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chUnderscore,chLatin_s,chLatin_u,chLatin_f,chLatin_f,chLatin_i,chLatin_x, chNull }; // tiger:name_direction_suffix
static XMLCh szTIGER_NAME_DIRECTION_SUFFIX_1[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_d,chLatin_i,chLatin_r,chLatin_e,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chUnderscore,chLatin_s,chLatin_u,chLatin_f,chLatin_f,chLatin_i,chLatin_x,chUnderscore,chDigit_1, chNull }; // tiger:name_direction_suffix_1
static XMLCh szTIGER_NAME_DIRECTION_SUFFIX_2[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_d,chLatin_i,chLatin_r,chLatin_e,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chUnderscore,chLatin_s,chLatin_u,chLatin_f,chLatin_f,chLatin_i,chLatin_x,chUnderscore,chDigit_2, chNull }; // tiger:name_direction_suffix_2
static XMLCh szTIGER_NAME_DIRECTION_SUFFIX_3[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_d,chLatin_i,chLatin_r,chLatin_e,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chUnderscore,chLatin_s,chLatin_u,chLatin_f,chLatin_f,chLatin_i,chLatin_x,chUnderscore,chDigit_3, chNull }; // tiger:name_direction_suffix_3
static XMLCh szTIGER_NAME_TYPE[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_t,chLatin_y,chLatin_p,chLatin_e, chNull }; // tiger:name_type
static XMLCh szTIGER_NAME_TYPE_1[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_t,chLatin_y,chLatin_p,chLatin_e,chUnderscore,chDigit_1, chNull }; // tiger:name_type_1
static XMLCh szTIGER_NAME_TYPE_2[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_t,chLatin_y,chLatin_p,chLatin_e,chUnderscore,chDigit_2, chNull }; // tiger:name_type_2
static XMLCh szTIGER_NAME_TYPE_3[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_t,chLatin_y,chLatin_p,chLatin_e,chUnderscore,chDigit_3, chNull }; // tiger:name_type_3
static XMLCh szTIGER_NAME_TYPE_4[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_t,chLatin_y,chLatin_p,chLatin_e,chUnderscore,chDigit_4, chNull }; // tiger:name_type_4
static XMLCh szTIGER_NAME_TYPE_5[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_n,chLatin_a,chLatin_m,chLatin_e,chUnderscore,chLatin_t,chLatin_y,chLatin_p,chLatin_e,chUnderscore,chDigit_5, chNull }; // tiger:name_type_5
static XMLCh szTIGER_PCICBSA[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_P,chLatin_C,chLatin_I,chLatin_C,chLatin_B,chLatin_S,chLatin_A, chNull }; // tiger:PCICBSA

static XMLCh szTIGER_PCINECTA[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_P,chLatin_C,chLatin_I,chLatin_N,chLatin_E,chLatin_C,chLatin_T,chLatin_A, chNull }; // tiger:PCINECTA


static XMLCh szTIGER_PLACEFP[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_P,chLatin_L,chLatin_A,chLatin_C,chLatin_E,chLatin_F,chLatin_P, chNull }; // tiger:PLACEFP

static XMLCh szTIGER_PLACENS[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_P,chLatin_L,chLatin_A,chLatin_C,chLatin_E,chLatin_N,chLatin_S, chNull }; // tiger:PLACENS

static XMLCh szTIGER_PLCIDFP[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_P,chLatin_L,chLatin_C,chLatin_I,chLatin_D,chLatin_F,chLatin_P, chNull }; // tiger:PLCIDFP

static XMLCh szTIGER_REVIEWED[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_r,chLatin_e,chLatin_v,chLatin_i,chLatin_e,chLatin_w,chLatin_e,chLatin_d, chNull }; // tiger:reviewed
static XMLCh szTIGER_SEPARATED[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_s,chLatin_e,chLatin_p,chLatin_a,chLatin_r,chLatin_a,chLatin_t,chLatin_e,chLatin_d, chNull }; // tiger:separated
static XMLCh szTIGER_SOURCE[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_s,chLatin_o,chLatin_u,chLatin_r,chLatin_c,chLatin_e, chNull }; // tiger:source

static XMLCh szTIGER_STATEFP[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_S,chLatin_T,chLatin_A,chLatin_T,chLatin_E,chLatin_F,chLatin_P, chNull }; // tiger:STATEFP
static XMLCh szTIGER_TLID[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_t,chLatin_l,chLatin_i,chLatin_d, chNull }; // tiger:tlid
static XMLCh szTIGER_TLID_1[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_t,chLatin_l,chLatin_i,chLatin_d,chUnderscore,chDigit_1, chNull }; // tiger:tlid_1
static XMLCh szTIGER_TLID_2[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_t,chLatin_l,chLatin_i,chLatin_d,chUnderscore,chDigit_2, chNull }; // tiger:tlid_2
static XMLCh szTIGER_UPLOAD_UUID[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_u,chLatin_p,chLatin_l,chLatin_o,chLatin_a,chLatin_d,chUnderscore,chLatin_u,chLatin_u,chLatin_i,chLatin_d, chNull }; // tiger:upload_uuid
static XMLCh szTIGER_ZIP_LEFT[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t, chNull }; // tiger:zip_left
static XMLCh szTIGER_ZIP_LEFT_100[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_0, chNull }; // tiger:zip_left_100
static XMLCh szTIGER_ZIP_LEFT_101[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_1, chNull }; // tiger:zip_left_101
static XMLCh szTIGER_ZIP_LEFT_102[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_2, chNull }; // tiger:zip_left_102
static XMLCh szTIGER_ZIP_LEFT_103[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_3, chNull }; // tiger:zip_left_103
static XMLCh szTIGER_ZIP_LEFT_104[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_4, chNull }; // tiger:zip_left_104
static XMLCh szTIGER_ZIP_LEFT_105[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_5, chNull }; // tiger:zip_left_105
static XMLCh szTIGER_ZIP_LEFT_106[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_6, chNull }; // tiger:zip_left_106
static XMLCh szTIGER_ZIP_LEFT_107[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_7, chNull }; // tiger:zip_left_107
static XMLCh szTIGER_ZIP_LEFT_108[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_8, chNull }; // tiger:zip_left_108
static XMLCh szTIGER_ZIP_LEFT_109[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_9, chNull }; // tiger:zip_left_109
static XMLCh szTIGER_ZIP_LEFT_10[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_0, chNull }; // tiger:zip_left_10
static XMLCh szTIGER_ZIP_LEFT_110[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_1,chDigit_0, chNull }; // tiger:zip_left_110
static XMLCh szTIGER_ZIP_LEFT_111[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_1,chDigit_1, chNull }; // tiger:zip_left_111
static XMLCh szTIGER_ZIP_LEFT_112[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_1,chDigit_2, chNull }; // tiger:zip_left_112
static XMLCh szTIGER_ZIP_LEFT_113[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_1,chDigit_3, chNull }; // tiger:zip_left_113
static XMLCh szTIGER_ZIP_LEFT_114[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_1,chDigit_4, chNull }; // tiger:zip_left_114
static XMLCh szTIGER_ZIP_LEFT_115[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_1,chDigit_5, chNull }; // tiger:zip_left_115
static XMLCh szTIGER_ZIP_LEFT_116[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_1,chDigit_6, chNull }; // tiger:zip_left_116
static XMLCh szTIGER_ZIP_LEFT_117[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_1,chDigit_7, chNull }; // tiger:zip_left_117
static XMLCh szTIGER_ZIP_LEFT_118[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_1,chDigit_8, chNull }; // tiger:zip_left_118
static XMLCh szTIGER_ZIP_LEFT_119[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_1,chDigit_9, chNull }; // tiger:zip_left_119
static XMLCh szTIGER_ZIP_LEFT_11[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_1, chNull }; // tiger:zip_left_11
static XMLCh szTIGER_ZIP_LEFT_120[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_2,chDigit_0, chNull }; // tiger:zip_left_120
static XMLCh szTIGER_ZIP_LEFT_121[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_2,chDigit_1, chNull }; // tiger:zip_left_121
static XMLCh szTIGER_ZIP_LEFT_122[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_2,chDigit_2, chNull }; // tiger:zip_left_122
static XMLCh szTIGER_ZIP_LEFT_123[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_2,chDigit_3, chNull }; // tiger:zip_left_123
static XMLCh szTIGER_ZIP_LEFT_124[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_2,chDigit_4, chNull }; // tiger:zip_left_124
static XMLCh szTIGER_ZIP_LEFT_125[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_2,chDigit_5, chNull }; // tiger:zip_left_125
static XMLCh szTIGER_ZIP_LEFT_126[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_2,chDigit_6, chNull }; // tiger:zip_left_126
static XMLCh szTIGER_ZIP_LEFT_127[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_2,chDigit_7, chNull }; // tiger:zip_left_127
static XMLCh szTIGER_ZIP_LEFT_128[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_2,chDigit_8, chNull }; // tiger:zip_left_128
static XMLCh szTIGER_ZIP_LEFT_129[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_2,chDigit_9, chNull }; // tiger:zip_left_129
static XMLCh szTIGER_ZIP_LEFT_12[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_2, chNull }; // tiger:zip_left_12
static XMLCh szTIGER_ZIP_LEFT_130[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_3,chDigit_0, chNull }; // tiger:zip_left_130
static XMLCh szTIGER_ZIP_LEFT_131[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_3,chDigit_1, chNull }; // tiger:zip_left_131
static XMLCh szTIGER_ZIP_LEFT_132[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_3,chDigit_2, chNull }; // tiger:zip_left_132
static XMLCh szTIGER_ZIP_LEFT_133[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_3,chDigit_3, chNull }; // tiger:zip_left_133
static XMLCh szTIGER_ZIP_LEFT_134[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_3,chDigit_4, chNull }; // tiger:zip_left_134
static XMLCh szTIGER_ZIP_LEFT_135[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_3,chDigit_5, chNull }; // tiger:zip_left_135
static XMLCh szTIGER_ZIP_LEFT_136[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_3,chDigit_6, chNull }; // tiger:zip_left_136
static XMLCh szTIGER_ZIP_LEFT_137[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_3,chDigit_7, chNull }; // tiger:zip_left_137
static XMLCh szTIGER_ZIP_LEFT_138[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_3,chDigit_8, chNull }; // tiger:zip_left_138
static XMLCh szTIGER_ZIP_LEFT_139[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_3,chDigit_9, chNull }; // tiger:zip_left_139
static XMLCh szTIGER_ZIP_LEFT_13[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_3, chNull }; // tiger:zip_left_13
static XMLCh szTIGER_ZIP_LEFT_140[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_4,chDigit_0, chNull }; // tiger:zip_left_140
static XMLCh szTIGER_ZIP_LEFT_141[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_4,chDigit_1, chNull }; // tiger:zip_left_141
static XMLCh szTIGER_ZIP_LEFT_142[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_4,chDigit_2, chNull }; // tiger:zip_left_142
static XMLCh szTIGER_ZIP_LEFT_143[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_4,chDigit_3, chNull }; // tiger:zip_left_143
static XMLCh szTIGER_ZIP_LEFT_144[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_4,chDigit_4, chNull }; // tiger:zip_left_144
static XMLCh szTIGER_ZIP_LEFT_145[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_4,chDigit_5, chNull }; // tiger:zip_left_145
static XMLCh szTIGER_ZIP_LEFT_146[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_4,chDigit_6, chNull }; // tiger:zip_left_146
static XMLCh szTIGER_ZIP_LEFT_147[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_4,chDigit_7, chNull }; // tiger:zip_left_147
static XMLCh szTIGER_ZIP_LEFT_148[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_4,chDigit_8, chNull }; // tiger:zip_left_148
static XMLCh szTIGER_ZIP_LEFT_149[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_4,chDigit_9, chNull }; // tiger:zip_left_149
static XMLCh szTIGER_ZIP_LEFT_14[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_4, chNull }; // tiger:zip_left_14
static XMLCh szTIGER_ZIP_LEFT_150[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_5,chDigit_0, chNull }; // tiger:zip_left_150
static XMLCh szTIGER_ZIP_LEFT_151[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_5,chDigit_1, chNull }; // tiger:zip_left_151
static XMLCh szTIGER_ZIP_LEFT_152[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_5,chDigit_2, chNull }; // tiger:zip_left_152
static XMLCh szTIGER_ZIP_LEFT_153[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_5,chDigit_3, chNull }; // tiger:zip_left_153
static XMLCh szTIGER_ZIP_LEFT_154[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_5,chDigit_4, chNull }; // tiger:zip_left_154
static XMLCh szTIGER_ZIP_LEFT_155[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_5,chDigit_5, chNull }; // tiger:zip_left_155
static XMLCh szTIGER_ZIP_LEFT_156[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_5,chDigit_6, chNull }; // tiger:zip_left_156
static XMLCh szTIGER_ZIP_LEFT_157[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_5,chDigit_7, chNull }; // tiger:zip_left_157
static XMLCh szTIGER_ZIP_LEFT_158[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_5,chDigit_8, chNull }; // tiger:zip_left_158
static XMLCh szTIGER_ZIP_LEFT_159[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_5,chDigit_9, chNull }; // tiger:zip_left_159
static XMLCh szTIGER_ZIP_LEFT_15[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_5, chNull }; // tiger:zip_left_15
static XMLCh szTIGER_ZIP_LEFT_160[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_6,chDigit_0, chNull }; // tiger:zip_left_160
static XMLCh szTIGER_ZIP_LEFT_161[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_6,chDigit_1, chNull }; // tiger:zip_left_161
static XMLCh szTIGER_ZIP_LEFT_162[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_6,chDigit_2, chNull }; // tiger:zip_left_162
static XMLCh szTIGER_ZIP_LEFT_163[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_6,chDigit_3, chNull }; // tiger:zip_left_163
static XMLCh szTIGER_ZIP_LEFT_164[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_6,chDigit_4, chNull }; // tiger:zip_left_164
static XMLCh szTIGER_ZIP_LEFT_165[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_6,chDigit_5, chNull }; // tiger:zip_left_165
static XMLCh szTIGER_ZIP_LEFT_166[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_6,chDigit_6, chNull }; // tiger:zip_left_166
static XMLCh szTIGER_ZIP_LEFT_167[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_6,chDigit_7, chNull }; // tiger:zip_left_167
static XMLCh szTIGER_ZIP_LEFT_168[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_6,chDigit_8, chNull }; // tiger:zip_left_168
static XMLCh szTIGER_ZIP_LEFT_169[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_6,chDigit_9, chNull }; // tiger:zip_left_169
static XMLCh szTIGER_ZIP_LEFT_16[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_6, chNull }; // tiger:zip_left_16
static XMLCh szTIGER_ZIP_LEFT_170[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_7,chDigit_0, chNull }; // tiger:zip_left_170
static XMLCh szTIGER_ZIP_LEFT_171[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_7,chDigit_1, chNull }; // tiger:zip_left_171
static XMLCh szTIGER_ZIP_LEFT_172[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_7,chDigit_2, chNull }; // tiger:zip_left_172
static XMLCh szTIGER_ZIP_LEFT_173[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_7,chDigit_3, chNull }; // tiger:zip_left_173
static XMLCh szTIGER_ZIP_LEFT_174[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_7,chDigit_4, chNull }; // tiger:zip_left_174
static XMLCh szTIGER_ZIP_LEFT_175[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_7,chDigit_5, chNull }; // tiger:zip_left_175
static XMLCh szTIGER_ZIP_LEFT_176[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_7,chDigit_6, chNull }; // tiger:zip_left_176
static XMLCh szTIGER_ZIP_LEFT_177[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_7,chDigit_7, chNull }; // tiger:zip_left_177
static XMLCh szTIGER_ZIP_LEFT_178[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_7,chDigit_8, chNull }; // tiger:zip_left_178
static XMLCh szTIGER_ZIP_LEFT_179[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_7,chDigit_9, chNull }; // tiger:zip_left_179
static XMLCh szTIGER_ZIP_LEFT_17[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_7, chNull }; // tiger:zip_left_17
static XMLCh szTIGER_ZIP_LEFT_180[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_8,chDigit_0, chNull }; // tiger:zip_left_180
static XMLCh szTIGER_ZIP_LEFT_181[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_8,chDigit_1, chNull }; // tiger:zip_left_181
static XMLCh szTIGER_ZIP_LEFT_182[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_8,chDigit_2, chNull }; // tiger:zip_left_182
static XMLCh szTIGER_ZIP_LEFT_183[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_8,chDigit_3, chNull }; // tiger:zip_left_183
static XMLCh szTIGER_ZIP_LEFT_184[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_8,chDigit_4, chNull }; // tiger:zip_left_184
static XMLCh szTIGER_ZIP_LEFT_185[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_8,chDigit_5, chNull }; // tiger:zip_left_185
static XMLCh szTIGER_ZIP_LEFT_186[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_8,chDigit_6, chNull }; // tiger:zip_left_186
static XMLCh szTIGER_ZIP_LEFT_187[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_8,chDigit_7, chNull }; // tiger:zip_left_187
static XMLCh szTIGER_ZIP_LEFT_188[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_8,chDigit_8, chNull }; // tiger:zip_left_188
static XMLCh szTIGER_ZIP_LEFT_189[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_8,chDigit_9, chNull }; // tiger:zip_left_189
static XMLCh szTIGER_ZIP_LEFT_18[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_8, chNull }; // tiger:zip_left_18
static XMLCh szTIGER_ZIP_LEFT_190[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_9,chDigit_0, chNull }; // tiger:zip_left_190
static XMLCh szTIGER_ZIP_LEFT_191[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_9,chDigit_1, chNull }; // tiger:zip_left_191
static XMLCh szTIGER_ZIP_LEFT_192[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_9,chDigit_2, chNull }; // tiger:zip_left_192
static XMLCh szTIGER_ZIP_LEFT_193[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_9,chDigit_3, chNull }; // tiger:zip_left_193
static XMLCh szTIGER_ZIP_LEFT_194[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_9,chDigit_4, chNull }; // tiger:zip_left_194
static XMLCh szTIGER_ZIP_LEFT_195[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_9,chDigit_5, chNull }; // tiger:zip_left_195
static XMLCh szTIGER_ZIP_LEFT_196[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_9,chDigit_6, chNull }; // tiger:zip_left_196
static XMLCh szTIGER_ZIP_LEFT_197[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_9,chDigit_7, chNull }; // tiger:zip_left_197
static XMLCh szTIGER_ZIP_LEFT_198[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_9,chDigit_8, chNull }; // tiger:zip_left_198
static XMLCh szTIGER_ZIP_LEFT_199[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_9,chDigit_9, chNull }; // tiger:zip_left_199
static XMLCh szTIGER_ZIP_LEFT_19[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1,chDigit_9, chNull }; // tiger:zip_left_19
static XMLCh szTIGER_ZIP_LEFT_1[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_1, chNull }; // tiger:zip_left_1
static XMLCh szTIGER_ZIP_LEFT_200[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_0,chDigit_0, chNull }; // tiger:zip_left_200
static XMLCh szTIGER_ZIP_LEFT_201[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_0,chDigit_1, chNull }; // tiger:zip_left_201
static XMLCh szTIGER_ZIP_LEFT_202[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_0,chDigit_2, chNull }; // tiger:zip_left_202
static XMLCh szTIGER_ZIP_LEFT_203[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_0,chDigit_3, chNull }; // tiger:zip_left_203
static XMLCh szTIGER_ZIP_LEFT_204[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_0,chDigit_4, chNull }; // tiger:zip_left_204
static XMLCh szTIGER_ZIP_LEFT_205[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_0,chDigit_5, chNull }; // tiger:zip_left_205
static XMLCh szTIGER_ZIP_LEFT_206[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_0,chDigit_6, chNull }; // tiger:zip_left_206
static XMLCh szTIGER_ZIP_LEFT_207[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_0,chDigit_7, chNull }; // tiger:zip_left_207
static XMLCh szTIGER_ZIP_LEFT_20[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_0, chNull }; // tiger:zip_left_20
static XMLCh szTIGER_ZIP_LEFT_21[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_1, chNull }; // tiger:zip_left_21
static XMLCh szTIGER_ZIP_LEFT_22[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_2, chNull }; // tiger:zip_left_22
static XMLCh szTIGER_ZIP_LEFT_23[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_3, chNull }; // tiger:zip_left_23
static XMLCh szTIGER_ZIP_LEFT_24[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_4, chNull }; // tiger:zip_left_24
static XMLCh szTIGER_ZIP_LEFT_25[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_5, chNull }; // tiger:zip_left_25
static XMLCh szTIGER_ZIP_LEFT_26[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_6, chNull }; // tiger:zip_left_26
static XMLCh szTIGER_ZIP_LEFT_27[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_7, chNull }; // tiger:zip_left_27
static XMLCh szTIGER_ZIP_LEFT_28[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_8, chNull }; // tiger:zip_left_28
static XMLCh szTIGER_ZIP_LEFT_29[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2,chDigit_9, chNull }; // tiger:zip_left_29
static XMLCh szTIGER_ZIP_LEFT_2[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_2, chNull }; // tiger:zip_left_2
static XMLCh szTIGER_ZIP_LEFT_30[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_3,chDigit_0, chNull }; // tiger:zip_left_30
static XMLCh szTIGER_ZIP_LEFT_31[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_3,chDigit_1, chNull }; // tiger:zip_left_31
static XMLCh szTIGER_ZIP_LEFT_32[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_3,chDigit_2, chNull }; // tiger:zip_left_32
static XMLCh szTIGER_ZIP_LEFT_33[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_3,chDigit_3, chNull }; // tiger:zip_left_33
static XMLCh szTIGER_ZIP_LEFT_34[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_3,chDigit_4, chNull }; // tiger:zip_left_34
static XMLCh szTIGER_ZIP_LEFT_35[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_3,chDigit_5, chNull }; // tiger:zip_left_35
static XMLCh szTIGER_ZIP_LEFT_36[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_3,chDigit_6, chNull }; // tiger:zip_left_36
static XMLCh szTIGER_ZIP_LEFT_37[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_3,chDigit_7, chNull }; // tiger:zip_left_37
static XMLCh szTIGER_ZIP_LEFT_38[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_3,chDigit_8, chNull }; // tiger:zip_left_38
static XMLCh szTIGER_ZIP_LEFT_39[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_3,chDigit_9, chNull }; // tiger:zip_left_39
static XMLCh szTIGER_ZIP_LEFT_3[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_3, chNull }; // tiger:zip_left_3
static XMLCh szTIGER_ZIP_LEFT_40[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_4,chDigit_0, chNull }; // tiger:zip_left_40
static XMLCh szTIGER_ZIP_LEFT_41[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_4,chDigit_1, chNull }; // tiger:zip_left_41
static XMLCh szTIGER_ZIP_LEFT_42[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_4,chDigit_2, chNull }; // tiger:zip_left_42
static XMLCh szTIGER_ZIP_LEFT_43[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_4,chDigit_3, chNull }; // tiger:zip_left_43
static XMLCh szTIGER_ZIP_LEFT_44[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_4,chDigit_4, chNull }; // tiger:zip_left_44
static XMLCh szTIGER_ZIP_LEFT_45[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_4,chDigit_5, chNull }; // tiger:zip_left_45
static XMLCh szTIGER_ZIP_LEFT_46[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_4,chDigit_6, chNull }; // tiger:zip_left_46
static XMLCh szTIGER_ZIP_LEFT_47[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_4,chDigit_7, chNull }; // tiger:zip_left_47
static XMLCh szTIGER_ZIP_LEFT_48[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_4,chDigit_8, chNull }; // tiger:zip_left_48
static XMLCh szTIGER_ZIP_LEFT_49[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_4,chDigit_9, chNull }; // tiger:zip_left_49
static XMLCh szTIGER_ZIP_LEFT_4[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_4, chNull }; // tiger:zip_left_4
static XMLCh szTIGER_ZIP_LEFT_50[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_5,chDigit_0, chNull }; // tiger:zip_left_50
static XMLCh szTIGER_ZIP_LEFT_51[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_5,chDigit_1, chNull }; // tiger:zip_left_51
static XMLCh szTIGER_ZIP_LEFT_52[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_5,chDigit_2, chNull }; // tiger:zip_left_52
static XMLCh szTIGER_ZIP_LEFT_53[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_5,chDigit_3, chNull }; // tiger:zip_left_53
static XMLCh szTIGER_ZIP_LEFT_54[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_5,chDigit_4, chNull }; // tiger:zip_left_54
static XMLCh szTIGER_ZIP_LEFT_55[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_5,chDigit_5, chNull }; // tiger:zip_left_55
static XMLCh szTIGER_ZIP_LEFT_56[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_5,chDigit_6, chNull }; // tiger:zip_left_56
static XMLCh szTIGER_ZIP_LEFT_57[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_5,chDigit_7, chNull }; // tiger:zip_left_57
static XMLCh szTIGER_ZIP_LEFT_58[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_5,chDigit_8, chNull }; // tiger:zip_left_58
static XMLCh szTIGER_ZIP_LEFT_59[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_5,chDigit_9, chNull }; // tiger:zip_left_59
static XMLCh szTIGER_ZIP_LEFT_5[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_5, chNull }; // tiger:zip_left_5
static XMLCh szTIGER_ZIP_LEFT_60[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_6,chDigit_0, chNull }; // tiger:zip_left_60
static XMLCh szTIGER_ZIP_LEFT_61[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_6,chDigit_1, chNull }; // tiger:zip_left_61
static XMLCh szTIGER_ZIP_LEFT_62[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_6,chDigit_2, chNull }; // tiger:zip_left_62
static XMLCh szTIGER_ZIP_LEFT_63[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_6,chDigit_3, chNull }; // tiger:zip_left_63
static XMLCh szTIGER_ZIP_LEFT_64[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_6,chDigit_4, chNull }; // tiger:zip_left_64
static XMLCh szTIGER_ZIP_LEFT_65[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_6,chDigit_5, chNull }; // tiger:zip_left_65
static XMLCh szTIGER_ZIP_LEFT_66[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_6,chDigit_6, chNull }; // tiger:zip_left_66
static XMLCh szTIGER_ZIP_LEFT_67[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_6,chDigit_7, chNull }; // tiger:zip_left_67
static XMLCh szTIGER_ZIP_LEFT_68[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_6,chDigit_8, chNull }; // tiger:zip_left_68
static XMLCh szTIGER_ZIP_LEFT_69[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_6,chDigit_9, chNull }; // tiger:zip_left_69
static XMLCh szTIGER_ZIP_LEFT_6[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_6, chNull }; // tiger:zip_left_6
static XMLCh szTIGER_ZIP_LEFT_70[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_7,chDigit_0, chNull }; // tiger:zip_left_70
static XMLCh szTIGER_ZIP_LEFT_71[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_7,chDigit_1, chNull }; // tiger:zip_left_71
static XMLCh szTIGER_ZIP_LEFT_72[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_7,chDigit_2, chNull }; // tiger:zip_left_72
static XMLCh szTIGER_ZIP_LEFT_73[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_7,chDigit_3, chNull }; // tiger:zip_left_73
static XMLCh szTIGER_ZIP_LEFT_74[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_7,chDigit_4, chNull }; // tiger:zip_left_74
static XMLCh szTIGER_ZIP_LEFT_75[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_7,chDigit_5, chNull }; // tiger:zip_left_75
static XMLCh szTIGER_ZIP_LEFT_76[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_7,chDigit_6, chNull }; // tiger:zip_left_76
static XMLCh szTIGER_ZIP_LEFT_77[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_7,chDigit_7, chNull }; // tiger:zip_left_77
static XMLCh szTIGER_ZIP_LEFT_78[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_7,chDigit_8, chNull }; // tiger:zip_left_78
static XMLCh szTIGER_ZIP_LEFT_79[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_7,chDigit_9, chNull }; // tiger:zip_left_79
static XMLCh szTIGER_ZIP_LEFT_7[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_7, chNull }; // tiger:zip_left_7
static XMLCh szTIGER_ZIP_LEFT_80[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_8,chDigit_0, chNull }; // tiger:zip_left_80
static XMLCh szTIGER_ZIP_LEFT_81[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_8,chDigit_1, chNull }; // tiger:zip_left_81
static XMLCh szTIGER_ZIP_LEFT_82[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_8,chDigit_2, chNull }; // tiger:zip_left_82
static XMLCh szTIGER_ZIP_LEFT_83[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_8,chDigit_3, chNull }; // tiger:zip_left_83
static XMLCh szTIGER_ZIP_LEFT_84[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_8,chDigit_4, chNull }; // tiger:zip_left_84
static XMLCh szTIGER_ZIP_LEFT_85[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_8,chDigit_5, chNull }; // tiger:zip_left_85
static XMLCh szTIGER_ZIP_LEFT_86[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_8,chDigit_6, chNull }; // tiger:zip_left_86
static XMLCh szTIGER_ZIP_LEFT_87[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_8,chDigit_7, chNull }; // tiger:zip_left_87
static XMLCh szTIGER_ZIP_LEFT_88[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_8,chDigit_8, chNull }; // tiger:zip_left_88
static XMLCh szTIGER_ZIP_LEFT_89[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_8,chDigit_9, chNull }; // tiger:zip_left_89
static XMLCh szTIGER_ZIP_LEFT_8[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_8, chNull }; // tiger:zip_left_8
static XMLCh szTIGER_ZIP_LEFT_90[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_9,chDigit_0, chNull }; // tiger:zip_left_90
static XMLCh szTIGER_ZIP_LEFT_91[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_9,chDigit_1, chNull }; // tiger:zip_left_91
static XMLCh szTIGER_ZIP_LEFT_92[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_9,chDigit_2, chNull }; // tiger:zip_left_92
static XMLCh szTIGER_ZIP_LEFT_93[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_9,chDigit_3, chNull }; // tiger:zip_left_93
static XMLCh szTIGER_ZIP_LEFT_94[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_9,chDigit_4, chNull }; // tiger:zip_left_94
static XMLCh szTIGER_ZIP_LEFT_95[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_9,chDigit_5, chNull }; // tiger:zip_left_95
static XMLCh szTIGER_ZIP_LEFT_96[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_9,chDigit_6, chNull }; // tiger:zip_left_96
static XMLCh szTIGER_ZIP_LEFT_97[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_9,chDigit_7, chNull }; // tiger:zip_left_97
static XMLCh szTIGER_ZIP_LEFT_98[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_9,chDigit_8, chNull }; // tiger:zip_left_98
static XMLCh szTIGER_ZIP_LEFT_99[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_9,chDigit_9, chNull }; // tiger:zip_left_99
static XMLCh szTIGER_ZIP_LEFT_9[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_l,chLatin_e,chLatin_f,chLatin_t,chUnderscore,chDigit_9, chNull }; // tiger:zip_left_9
static XMLCh szTIGER_ZIP_RIGHT[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t, chNull }; // tiger:zip_right
static XMLCh szTIGER_ZIP_RIGHT_100[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_0, chNull }; // tiger:zip_right_100
static XMLCh szTIGER_ZIP_RIGHT_101[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_1, chNull }; // tiger:zip_right_101
static XMLCh szTIGER_ZIP_RIGHT_102[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_2, chNull }; // tiger:zip_right_102
static XMLCh szTIGER_ZIP_RIGHT_103[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_3, chNull }; // tiger:zip_right_103
static XMLCh szTIGER_ZIP_RIGHT_104[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_4, chNull }; // tiger:zip_right_104
static XMLCh szTIGER_ZIP_RIGHT_105[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_5, chNull }; // tiger:zip_right_105
static XMLCh szTIGER_ZIP_RIGHT_106[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_0,chDigit_6, chNull }; // tiger:zip_right_106
static XMLCh szTIGER_ZIP_RIGHT_10[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_0, chNull }; // tiger:zip_right_10
static XMLCh szTIGER_ZIP_RIGHT_11[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_1, chNull }; // tiger:zip_right_11
static XMLCh szTIGER_ZIP_RIGHT_12[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_2, chNull }; // tiger:zip_right_12
static XMLCh szTIGER_ZIP_RIGHT_13[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_3, chNull }; // tiger:zip_right_13
static XMLCh szTIGER_ZIP_RIGHT_14[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_4, chNull }; // tiger:zip_right_14
static XMLCh szTIGER_ZIP_RIGHT_15[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_5, chNull }; // tiger:zip_right_15
static XMLCh szTIGER_ZIP_RIGHT_16[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_6, chNull }; // tiger:zip_right_16
static XMLCh szTIGER_ZIP_RIGHT_170[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_7,chDigit_0, chNull }; // tiger:zip_right_170
static XMLCh szTIGER_ZIP_RIGHT_17[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_7, chNull }; // tiger:zip_right_17
static XMLCh szTIGER_ZIP_RIGHT_18[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_8, chNull }; // tiger:zip_right_18
static XMLCh szTIGER_ZIP_RIGHT_19[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1,chDigit_9, chNull }; // tiger:zip_right_19
static XMLCh szTIGER_ZIP_RIGHT_1[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_1, chNull }; // tiger:zip_right_1
static XMLCh szTIGER_ZIP_RIGHT_20[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_2,chDigit_0, chNull }; // tiger:zip_right_20
static XMLCh szTIGER_ZIP_RIGHT_21[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_2,chDigit_1, chNull }; // tiger:zip_right_21
static XMLCh szTIGER_ZIP_RIGHT_22[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_2,chDigit_2, chNull }; // tiger:zip_right_22
static XMLCh szTIGER_ZIP_RIGHT_23[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_2,chDigit_3, chNull }; // tiger:zip_right_23
static XMLCh szTIGER_ZIP_RIGHT_24[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_2,chDigit_4, chNull }; // tiger:zip_right_24
static XMLCh szTIGER_ZIP_RIGHT_25[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_2,chDigit_5, chNull }; // tiger:zip_right_25
static XMLCh szTIGER_ZIP_RIGHT_26[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_2,chDigit_6, chNull }; // tiger:zip_right_26
static XMLCh szTIGER_ZIP_RIGHT_27[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_2,chDigit_7, chNull }; // tiger:zip_right_27
static XMLCh szTIGER_ZIP_RIGHT_28[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_2,chDigit_8, chNull }; // tiger:zip_right_28
static XMLCh szTIGER_ZIP_RIGHT_29[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_2,chDigit_9, chNull }; // tiger:zip_right_29
static XMLCh szTIGER_ZIP_RIGHT_2[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_2, chNull }; // tiger:zip_right_2
static XMLCh szTIGER_ZIP_RIGHT_30[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_3,chDigit_0, chNull }; // tiger:zip_right_30
static XMLCh szTIGER_ZIP_RIGHT_31[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_3,chDigit_1, chNull }; // tiger:zip_right_31
static XMLCh szTIGER_ZIP_RIGHT_32[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_3,chDigit_2, chNull }; // tiger:zip_right_32
static XMLCh szTIGER_ZIP_RIGHT_33[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_3,chDigit_3, chNull }; // tiger:zip_right_33
static XMLCh szTIGER_ZIP_RIGHT_34[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_3,chDigit_4, chNull }; // tiger:zip_right_34
static XMLCh szTIGER_ZIP_RIGHT_35[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_3,chDigit_5, chNull }; // tiger:zip_right_35
static XMLCh szTIGER_ZIP_RIGHT_36[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_3,chDigit_6, chNull }; // tiger:zip_right_36
static XMLCh szTIGER_ZIP_RIGHT_37[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_3,chDigit_7, chNull }; // tiger:zip_right_37
static XMLCh szTIGER_ZIP_RIGHT_38[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_3,chDigit_8, chNull }; // tiger:zip_right_38
static XMLCh szTIGER_ZIP_RIGHT_39[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_3,chDigit_9, chNull }; // tiger:zip_right_39
static XMLCh szTIGER_ZIP_RIGHT_3[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_3, chNull }; // tiger:zip_right_3
static XMLCh szTIGER_ZIP_RIGHT_40[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_4,chDigit_0, chNull }; // tiger:zip_right_40
static XMLCh szTIGER_ZIP_RIGHT_41[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_4,chDigit_1, chNull }; // tiger:zip_right_41
static XMLCh szTIGER_ZIP_RIGHT_42[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_4,chDigit_2, chNull }; // tiger:zip_right_42
static XMLCh szTIGER_ZIP_RIGHT_43[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_4,chDigit_3, chNull }; // tiger:zip_right_43
static XMLCh szTIGER_ZIP_RIGHT_44[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_4,chDigit_4, chNull }; // tiger:zip_right_44
static XMLCh szTIGER_ZIP_RIGHT_45[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_4,chDigit_5, chNull }; // tiger:zip_right_45
static XMLCh szTIGER_ZIP_RIGHT_46[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_4,chDigit_6, chNull }; // tiger:zip_right_46
static XMLCh szTIGER_ZIP_RIGHT_47[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_4,chDigit_7, chNull }; // tiger:zip_right_47
static XMLCh szTIGER_ZIP_RIGHT_48[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_4,chDigit_8, chNull }; // tiger:zip_right_48
static XMLCh szTIGER_ZIP_RIGHT_49[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_4,chDigit_9, chNull }; // tiger:zip_right_49
static XMLCh szTIGER_ZIP_RIGHT_4[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_4, chNull }; // tiger:zip_right_4
static XMLCh szTIGER_ZIP_RIGHT_50[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_5,chDigit_0, chNull }; // tiger:zip_right_50
static XMLCh szTIGER_ZIP_RIGHT_51[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_5,chDigit_1, chNull }; // tiger:zip_right_51
static XMLCh szTIGER_ZIP_RIGHT_52[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_5,chDigit_2, chNull }; // tiger:zip_right_52
static XMLCh szTIGER_ZIP_RIGHT_53[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_5,chDigit_3, chNull }; // tiger:zip_right_53
static XMLCh szTIGER_ZIP_RIGHT_54[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_5,chDigit_4, chNull }; // tiger:zip_right_54
static XMLCh szTIGER_ZIP_RIGHT_55[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_5,chDigit_5, chNull }; // tiger:zip_right_55
static XMLCh szTIGER_ZIP_RIGHT_56[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_5,chDigit_6, chNull }; // tiger:zip_right_56
static XMLCh szTIGER_ZIP_RIGHT_57[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_5,chDigit_7, chNull }; // tiger:zip_right_57
static XMLCh szTIGER_ZIP_RIGHT_58[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_5,chDigit_8, chNull }; // tiger:zip_right_58
static XMLCh szTIGER_ZIP_RIGHT_59[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_5,chDigit_9, chNull }; // tiger:zip_right_59
static XMLCh szTIGER_ZIP_RIGHT_5[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_5, chNull }; // tiger:zip_right_5
static XMLCh szTIGER_ZIP_RIGHT_60[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_6,chDigit_0, chNull }; // tiger:zip_right_60
static XMLCh szTIGER_ZIP_RIGHT_61[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_6,chDigit_1, chNull }; // tiger:zip_right_61
static XMLCh szTIGER_ZIP_RIGHT_62[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_6,chDigit_2, chNull }; // tiger:zip_right_62
static XMLCh szTIGER_ZIP_RIGHT_63[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_6,chDigit_3, chNull }; // tiger:zip_right_63
static XMLCh szTIGER_ZIP_RIGHT_64[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_6,chDigit_4, chNull }; // tiger:zip_right_64
static XMLCh szTIGER_ZIP_RIGHT_65[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_6,chDigit_5, chNull }; // tiger:zip_right_65
static XMLCh szTIGER_ZIP_RIGHT_66[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_6,chDigit_6, chNull }; // tiger:zip_right_66
static XMLCh szTIGER_ZIP_RIGHT_67[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_6,chDigit_7, chNull }; // tiger:zip_right_67
static XMLCh szTIGER_ZIP_RIGHT_68[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_6,chDigit_8, chNull }; // tiger:zip_right_68
static XMLCh szTIGER_ZIP_RIGHT_69[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_6,chDigit_9, chNull }; // tiger:zip_right_69
static XMLCh szTIGER_ZIP_RIGHT_6[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_6, chNull }; // tiger:zip_right_6
static XMLCh szTIGER_ZIP_RIGHT_70[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_7,chDigit_0, chNull }; // tiger:zip_right_70
static XMLCh szTIGER_ZIP_RIGHT_71[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_7,chDigit_1, chNull }; // tiger:zip_right_71
static XMLCh szTIGER_ZIP_RIGHT_72[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_7,chDigit_2, chNull }; // tiger:zip_right_72
static XMLCh szTIGER_ZIP_RIGHT_73[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_7,chDigit_3, chNull }; // tiger:zip_right_73
static XMLCh szTIGER_ZIP_RIGHT_7[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_7, chNull }; // tiger:zip_right_7
static XMLCh szTIGER_ZIP_RIGHT_8[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_8, chNull }; // tiger:zip_right_8
static XMLCh szTIGER_ZIP_RIGHT_93[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_9,chDigit_3, chNull }; // tiger:zip_right_93
static XMLCh szTIGER_ZIP_RIGHT_96[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_9,chDigit_6, chNull }; // tiger:zip_right_96
static XMLCh szTIGER_ZIP_RIGHT_97[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_9,chDigit_7, chNull }; // tiger:zip_right_97
static XMLCh szTIGER_ZIP_RIGHT_98[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_9,chDigit_8, chNull }; // tiger:zip_right_98
static XMLCh szTIGER_ZIP_RIGHT_99[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_9,chDigit_9, chNull }; // tiger:zip_right_99
static XMLCh szTIGER_ZIP_RIGHT_9[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chColon,chLatin_z,chLatin_i,chLatin_p,chUnderscore,chLatin_r,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chUnderscore,chDigit_9, chNull }; // tiger:zip_right_9
static XMLCh szTODO[]={chLatin_T,chLatin_O,chLatin_D,chLatin_O, chNull }; // TODO
static XMLCh szTOLL[]={chLatin_t,chLatin_o,chLatin_l,chLatin_l, chNull }; // toll
static XMLCh szTOLL_BOOTH[]={chLatin_t,chLatin_o,chLatin_l,chLatin_l,chUnderscore,chLatin_b,chLatin_o,chLatin_o,chLatin_t,chLatin_h, chNull }; // toll_booth

static XMLCh szTOURSIM[]={chLatin_t,chLatin_o,chLatin_u,chLatin_r,chLatin_s,chLatin_i,chLatin_m, chNull }; // toursim
static XMLCh szTOWER_CONSTRUCTION[]={chLatin_t,chLatin_o,chLatin_w,chLatin_e,chLatin_r,chColon,chLatin_c,chLatin_o,chLatin_n,chLatin_s,chLatin_t,chLatin_r,chLatin_u,chLatin_c,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // tower:construction
static XMLCh szTOWER_TYPE[]={chLatin_t,chLatin_o,chLatin_w,chLatin_e,chLatin_r,chColon,chLatin_t,chLatin_y,chLatin_p,chLatin_e, chNull }; // tower:type
static XMLCh szTRACKS[]={chLatin_t,chLatin_r,chLatin_a,chLatin_c,chLatin_k,chLatin_s, chNull }; // tracks
static XMLCh szTRACKTYPE[]={chLatin_t,chLatin_r,chLatin_a,chLatin_c,chLatin_k,chLatin_t,chLatin_y,chLatin_p,chLatin_e, chNull }; // tracktype
static XMLCh szTRACK[]={chLatin_t,chLatin_r,chLatin_a,chLatin_c,chLatin_k, chNull }; // track
static XMLCh szTRAFFIC_CALMING[]={chLatin_t,chLatin_r,chLatin_a,chLatin_f,chLatin_f,chLatin_i,chLatin_c,chUnderscore,chLatin_c,chLatin_a,chLatin_l,chLatin_m,chLatin_i,chLatin_n,chLatin_g, chNull }; // traffic_calming
static XMLCh szTRAFFIC_LIGHTS[]={chLatin_t,chLatin_r,chLatin_a,chLatin_f,chLatin_f,chLatin_i,chLatin_c,chUnderscore,chLatin_l,chLatin_i,chLatin_g,chLatin_h,chLatin_t,chLatin_s, chNull }; // traffic_lights
static XMLCh szTRAFFIC_SIGNALS[]={chLatin_t,chLatin_r,chLatin_a,chLatin_f,chLatin_f,chLatin_i,chLatin_c,chUnderscore,chLatin_s,chLatin_i,chLatin_g,chLatin_n,chLatin_a,chLatin_l,chLatin_s, chNull }; // traffic_signals
static XMLCh szTRAIL_VISIBILITY[]={chLatin_t,chLatin_r,chLatin_a,chLatin_i,chLatin_l,chUnderscore,chLatin_v,chLatin_i,chLatin_s,chLatin_i,chLatin_b,chLatin_i,chLatin_l,chLatin_i,chLatin_t,chLatin_y, chNull }; // trail_visibility
static XMLCh szTRUNK[]={chLatin_t,chLatin_r,chLatin_u,chLatin_n,chLatin_k, chNull }; // trunk
static XMLCh szTRUNK_LINK[]={chLatin_t,chLatin_r,chLatin_u,chLatin_n,chLatin_k,chUnderscore,chLatin_l,chLatin_i,chLatin_n,chLatin_k, chNull }; // trunk_link
static XMLCh szTUNNEL[]={chLatin_t,chLatin_u,chLatin_n,chLatin_n,chLatin_e,chLatin_l, chNull }; // tunnel
static XMLCh szTURNING_CIRCLE[]={chLatin_t,chLatin_u,chLatin_r,chLatin_n,chLatin_i,chLatin_n,chLatin_g,chUnderscore,chLatin_c,chLatin_i,chLatin_r,chLatin_c,chLatin_l,chLatin_e, chNull }; // turning_circle
static XMLCh szTYPE[]={chLatin_t,chLatin_y,chLatin_p,chLatin_e, chNull }; // type

static XMLCh szUIC_REF[]={chLatin_u,chLatin_i,chLatin_c,chUnderscore,chLatin_r,chLatin_e,chLatin_f, chNull }; // uic_ref
static XMLCh szUNCLASSIFIED[]={chLatin_u,chLatin_n,chLatin_c,chLatin_l,chLatin_a,chLatin_s,chLatin_s,chLatin_i,chLatin_f,chLatin_i,chLatin_e,chLatin_d, chNull }; // unclassified
static XMLCh szUNDEFINED[]={chLatin_u,chLatin_n,chLatin_d,chLatin_e,chLatin_f,chLatin_i,chLatin_n,chLatin_e,chLatin_d, chNull }; // undefined
static XMLCh szUNSURFACED[]={chLatin_u,chLatin_n,chLatin_s,chLatin_u,chLatin_r,chLatin_f,chLatin_a,chLatin_c,chLatin_e,chLatin_d, chNull }; // unsurfaced

static XMLCh szURL[]={chLatin_u,chLatin_r,chLatin_l, chNull }; // url

static XMLCh szVALUE[]={chLatin_v,chLatin_a,chLatin_l,chLatin_u,chLatin_e, chNull }; // value
static XMLCh szVOLTAGE[]={chLatin_v,chLatin_o,chLatin_l,chLatin_t,chLatin_a,chLatin_g,chLatin_e, chNull }; // voltage
static XMLCh szWATERSHED[]={chLatin_w,chLatin_a,chLatin_t,chLatin_e,chLatin_r,chLatin_s,chLatin_h,chLatin_e,chLatin_d, chNull }; // watershed

static XMLCh szWATERWAY[]={chLatin_w,chLatin_a,chLatin_t,chLatin_e,chLatin_r,chLatin_w,chLatin_a,chLatin_y, chNull }; // waterway
static XMLCh szWEBSITE[]={chLatin_w,chLatin_e,chLatin_b,chLatin_s,chLatin_i,chLatin_t,chLatin_e, chNull }; // website
static XMLCh szWETLANDS[]={chLatin_w,chLatin_e,chLatin_t,chLatin_l,chLatin_a,chLatin_n,chLatin_d,chLatin_s, chNull }; // wetlands
static XMLCh szWETLAND[]={chLatin_w,chLatin_e,chLatin_t,chLatin_l,chLatin_a,chLatin_n,chLatin_d, chNull }; // wetland
static XMLCh szWHEELCHAIR[]={chLatin_w,chLatin_h,chLatin_e,chLatin_e,chLatin_l,chLatin_c,chLatin_h,chLatin_a,chLatin_i,chLatin_r, chNull }; // wheelchair
static XMLCh szWIDTH[]={chLatin_w,chLatin_i,chLatin_d,chLatin_t,chLatin_h, chNull }; // width

static XMLCh szWIKIPEDIA[]={chLatin_w,chLatin_i,chLatin_k,chLatin_i,chLatin_p,chLatin_e,chLatin_d,chLatin_i,chLatin_a, chNull }; // wikipedia
static XMLCh szWIKIPEDIA_EN[]={chLatin_w,chLatin_i,chLatin_k,chLatin_i,chLatin_p,chLatin_e,chLatin_d,chLatin_i,chLatin_a,chColon,chLatin_e,chLatin_n, chNull }; // wikipedia:en
static XMLCh szWIRES[]={chLatin_w,chLatin_i,chLatin_r,chLatin_e,chLatin_s, chNull }; // wires
static XMLCh szZCTA5CE[]={chLatin_Z,chLatin_C,chLatin_T,chLatin_A,chDigit_5,chLatin_C,chLatin_E, chNull }; // ZCTA5CE


// COUNTIES
// Nodes are tagged szATTRIBUTION=szUSGS_2001_COUNTY_BOUNDARY
// Nodes are tagged szsource=szUSGS_2001_COUNTY_BOUNDARY
static XMLCh szATTRIBUTION[]={chLatin_a,chLatin_t,chLatin_t,chLatin_r,chLatin_i,chLatin_b,chLatin_u,chLatin_t,chLatin_i,chLatin_o,chLatin_n, chNull }; // attribution


static XMLCh szUSGS_2001_COUNTY_BOUNDARY[]={chLatin_U,chLatin_S,chLatin_G,chLatin_S,chSpace,chDigit_2,chDigit_0,chDigit_0,chDigit_1,chSpace,chLatin_C,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y,chSpace,chLatin_B,chLatin_o,chLatin_u,chLatin_n,chLatin_d,chLatin_a,chLatin_r,chLatin_y, chNull }; // USGS 2001 County Boundary


static XMLCh szSOURCE[]={chLatin_s,chLatin_o,chLatin_u,chLatin_r,chLatin_c,chLatin_e, chNull }; // source

static XMLCh szCOUNTY_IMPORT_V0_1_20080508235458[]={chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y,chUnderscore,chLatin_i,chLatin_m,chLatin_p,chLatin_o,chLatin_r,chLatin_t,chUnderscore,chLatin_v,chDigit_0,chPeriod,chDigit_1,chUnderscore,chDigit_2,chDigit_0,chDigit_0,chDigit_8,chDigit_0,chDigit_5,chDigit_0,chDigit_8,chDigit_2,chDigit_3,chDigit_5,chDigit_4,chDigit_5,chDigit_8, chNull }; // county_import_v0.1_20080508235458
static XMLCh szCOUNTY_IMPORT_V0_1[]={chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y,chUnderscore,chLatin_i,chLatin_m,chLatin_p,chLatin_o,chLatin_r,chLatin_t,chUnderscore,chLatin_v,chDigit_0,chPeriod,chDigit_1, chNull }; // county_import_v0.1


  // WAY:
  // admin_level = 6
  // attribution = USGS 2001 County Boundary
  // border_type = county
  // boundary = administrative
  // name = New Castle County
  // source = county_import_v0.1_20080508235458


static XMLCh szADMIN_LEVEL[]={chLatin_a,chLatin_d,chLatin_m,chLatin_i,chLatin_n,chUnderscore,chLatin_l,chLatin_e,chLatin_v,chLatin_e,chLatin_l, chNull }; // admin_level
//
static XMLCh szBOUNDARY[]={chLatin_b,chLatin_o,chLatin_u,chLatin_n,chLatin_d,chLatin_a,chLatin_r,chLatin_y, chNull }; // boundary
static XMLCh szADMINISTRATIVE[]={chLatin_a,chLatin_d,chLatin_m,chLatin_i,chLatin_n,chLatin_i,chLatin_s,chLatin_t,chLatin_r,chLatin_a,chLatin_t,chLatin_i,chLatin_v,chLatin_e, chNull }; // administrative

static XMLCh szBORDER_TYPE[]={chLatin_b,chLatin_o,chLatin_r,chLatin_d,chLatin_e,chLatin_r,chUnderscore,chLatin_t,chLatin_y,chLatin_p,chLatin_e, chNull }; // border_type
static XMLCh szCOUNTY[]={chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y, chNull }; // county

static XMLCh szTIGER_IMPORT_DCH_V0_6_20070828[]={chLatin_t,chLatin_i,chLatin_g,chLatin_e,chLatin_r,chUnderscore,chLatin_i,chLatin_m,chLatin_p,chLatin_o,chLatin_r,chLatin_t,chUnderscore,chLatin_d,chLatin_c,chLatin_h,chUnderscore,chLatin_v,chDigit_0,chPeriod,chDigit_6,chUnderscore,chDigit_2,chDigit_0,chDigit_0,chDigit_7,chDigit_0,chDigit_8,chDigit_2,chDigit_8, chNull }; // tiger_import_dch_v0.6_20070828

static XMLCh szUNKNOWN_ATTRIBUTION_COUNTY_IMPORT_V0_1_20080508235449[]={chLatin_U,chLatin_n,chLatin_k,chLatin_n,chLatin_o,chLatin_w,chLatin_n,chSpace,chLatin_a,chLatin_t,chLatin_t,chLatin_r,chLatin_i,chLatin_b,chLatin_u,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chSpace,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y,chUnderscore,chLatin_i,chLatin_m,chLatin_p,chLatin_o,chLatin_r,chLatin_t,chUnderscore,chLatin_v,chDigit_0,chPeriod,chDigit_1,chUnderscore,chDigit_2,chDigit_0,chDigit_0,chDigit_8,chDigit_0,chDigit_5,chDigit_0,chDigit_8,chDigit_2,chDigit_3,chDigit_5,chDigit_4,chDigit_4,chDigit_9, chNull }; // Unknown attribution county_import_v0.1_20080508235449
static XMLCh szUNKNOWN_ATTRIBUTION_COUNTY_IMPORT_V0_1_20080508235452[]={chLatin_U,chLatin_n,chLatin_k,chLatin_n,chLatin_o,chLatin_w,chLatin_n,chSpace,chLatin_a,chLatin_t,chLatin_t,chLatin_r,chLatin_i,chLatin_b,chLatin_u,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chSpace,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y,chUnderscore,chLatin_i,chLatin_m,chLatin_p,chLatin_o,chLatin_r,chLatin_t,chUnderscore,chLatin_v,chDigit_0,chPeriod,chDigit_1,chUnderscore,chDigit_2,chDigit_0,chDigit_0,chDigit_8,chDigit_0,chDigit_5,chDigit_0,chDigit_8,chDigit_2,chDigit_3,chDigit_5,chDigit_4,chDigit_5,chDigit_2, chNull }; // Unknown attribution county_import_v0.1_20080508235452
static XMLCh szUNKNOWN_ATTRIBUTION_COUNTY_IMPORT_V0_1_20080508235456[]={chLatin_U,chLatin_n,chLatin_k,chLatin_n,chLatin_o,chLatin_w,chLatin_n,chSpace,chLatin_a,chLatin_t,chLatin_t,chLatin_r,chLatin_i,chLatin_b,chLatin_u,chLatin_t,chLatin_i,chLatin_o,chLatin_n,chSpace,chLatin_c,chLatin_o,chLatin_u,chLatin_n,chLatin_t,chLatin_y,chUnderscore,chLatin_i,chLatin_m,chLatin_p,chLatin_o,chLatin_r,chLatin_t,chUnderscore,chLatin_v,chDigit_0,chPeriod,chDigit_1,chUnderscore,chDigit_2,chDigit_0,chDigit_0,chDigit_8,chDigit_0,chDigit_5,chDigit_0,chDigit_8,chDigit_2,chDigit_3,chDigit_5,chDigit_4,chDigit_5,chDigit_6, chNull }; // Unknown attribution county_import_v0.1_20080508235456

//tiger:boundaries
// tiger_import_dch_v0.7_20071112


};
