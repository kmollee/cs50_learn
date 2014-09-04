/**
 * trainer.js
 *
 * week 9 section
 * fall 2013
 *
 * train dolphins
 */

$(document).ready(function()
{
    // put all of the dolphins in the ocean
    ocean_array = [];
    $.each(DOLPHINS, function(index, value)
    {
        ocean_array.push(value);
    });

    // no dolphins are in the pool to begin with
    pool = null;

    // draw the ocean
    draw_ocean();
    
    // train a dolphin when its picture is clicked
    // TODO
    
    // set a dolphin free when the button is clicked
    // TODO
});

/**
 * draws the ocean
 */
function draw_ocean()
{   
    // start HTML string
    var html = "<table><col width='150'><col width='150'><col width='150'><tr>";
    
    // store pictures of dolphins in the ocean in an HTML string
    // TODO
    
    // end HTML string
    html += "</tr></table>";
    
    // print out HTML string
    $("#ocean").html(html);
}

/**
 * draws the pool
 */
function draw_pool()
{
    // TODO
}


/**
 * moves a dolphin from the ocean to the pool
 */
function train(index)
{
    // TODO
}

/**
 * moves a dolphin from the pool to the ocean.
 */
function set_free(index)
{ 
    // TODO
}
