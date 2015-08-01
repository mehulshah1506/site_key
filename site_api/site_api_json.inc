<?php


/**
 * Implements Callback function.
 * 
 * @site_api_key 
 * Sites API key to validate against
 * 
 * @Page_nid
 * Node Id of content type Page
 * 
 * returns Json data of node
 */
function get_page_json($site_api_key, $page_nid) {
  $original_siteapikey = variable_get('siteapikey', 'No API Key yet');
  if ($original_siteapikey == $site_api_key) {
    if (_get_node_type_from_node_id($page_nid) == 'page') {
      $node = node_load($page_nid);
      drupal_json_output($node);
      exit();
    }
  }
  drupal_json_output('Access Denied');
  exit();
}


/**
 * Helper function to get type of node
 * 
 * @nid
 * Node Id of any content type
 * 
 * returns Type of node
 */
function _get_node_type_from_node_id($nid) {
  $query = db_select('node', 'n');
  $query->fields('n', array('type'));
  $query->condition('n.nid', $nid);
  return $query->execute()->fetchField();
}
