<?php
class openlayers_layer_type_mapbox extends openlayers_layer_type {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_type' => 'mapbox',
      'baselayer' => TRUE,
      'maxExtent' => array(-20037508.34,-20037508.34,20037508.34,20037508.34),
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form() {
    return array(
      'layername' => array(
        '#type' => 'textfield',
        '#title' => t('Layer Name'),
      ),
      'projection' =>
        array(
         '0' => array(
          '#type' => 'hidden',
          '#value' => '900913',
        ),
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'mapbox') .'/js/mapbox.js');
    return $this->options;
  }
}

