/**
 * trainer_completed.js
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
    $("#ocean").on("click", "td img", function()
    {
        train($(this).data("index"));
    });
    
    // set a dolphin free when the button is clicked
    $("#pool").on("click", "input", function()
    {
        set_free($(this).data("index"));
    });
});

/**
 * draws the ocean
 */
function draw_ocean()
{   
    // start HTML string
    var html = "<table><col width='150'><col width='150'><col width='150'><tr>";
    
    // store pictures of dolphins in the ocean in an HTML string
    $.each(ocean_array, function(index, value)
    {
        // three dolphins per row
        if (index % 3 == 0 && index > 0)
        {
            html += "</tr><tr>"
        }

        // store a dolphin if it's not being trained
        if (value == null)
        {
            html += "<td></td>";
        }
        else
        {
            html += "<td><img src='" + value.picture + "'";
            html += "data-index='" + index + "' width='150' height='100'></td>";
        }
    });
    
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
    // start HTML string
    var html = "";
    
    // check if a dolphin is in the pool
    if (pool != null)
    {
        html += "<p>Now training " + pool.name + "</p>";
        html += "<p>Type: " + pool.type + "</p>";
        html += "<p>Genus: " + pool.genus + "</p>";
        html += "<p>Length: " + pool.length + " feet</p>";
        html += "<p>Weight: " + pool.weight + " pounds</p>";
        html += "<input type='button' value='Set Free' data-index=" + pool.index + ">";
    }

    // print out HTML string
    $("#pool").html(html);
}


/**
 * moves a dolphin from the ocean to the pool
 */
function train(index)
{
    // only one dolphin can be trained at a time
    if (pool != null)
    {
        alert("You're already training a dolphin!");
        return;
    }
    
    // remove chosen dolphin from the ocean and put in the pool
    pool = ocean_array[index];
    pool.index = index;
    ocean_array[index] = null;
    
    // draw the ocean and the pool
    draw_ocean();
    draw_pool();
}

/**
 * moves a dolphin from the pool to the ocean.
 */
function set_free(index)
{ 
    // remove the dolphin from the pool and put in the ocean
    ocean_array[index] = pool;
    pool = null;
    
    // draw the ocean and the pool
    draw_ocean();
    draw_pool();
}
