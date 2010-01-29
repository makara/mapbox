<?php
class openlayers_layer_type_mapbox extends openlayers_layer_type {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'maxExtent' => array(-20037508.34,-20037508.34,20037508.34,20037508.34),
      'baselayer' => TRUE,
      'serverResolutions' => openlayers_get_resolutions('900913'),
      'maxExtent' => openlayers_get_extent('900913'),
      'projection' => array('900913'),
      'baselayer' => TRUE,
      'layer_handler' => 'MapBox',
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
        '#default_value' => $this->data['layername']
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_mapbox'
      ),
      'resolutions' => array(
        '#type' => 'select',
        '#multiple' => TRUE,
        '#options' => array_combine(
          array_map(strval, openlayers_get_resolutions('900913')), 
          range(0, 18)
        ),
        '#title' => t('Zoom Level Range'),
        '#default_value' => $this->data['resolutions'],
      ),
      'projection' =>
        array(
         '0' => array(
          '#type' => 'hidden',
          '#value' => '900913',
        ),
      ),
      '#default_value' => ($this->data['resolutions']) ? 
                              $this->data['resolutions'] : 
                              array_map(strval, openlayers_get_resolutions('900913'))
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'mapbox') .'/includes/layer_types/mapbox.js');
    drupal_add_css(drupal_get_path('module', 'mapbox') .'/js/mapbox.css');
    return $this->options;
  }
}

